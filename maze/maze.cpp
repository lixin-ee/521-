#include "maze.h"
#include "ui_maze.h"

maze::maze(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::maze)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/tubiao.ico"));
    setWindowTitle("maze521");
    resize((MX)*Label_Size,(MY+2)*Label_Size);
    Clabel=new QLabel(this);
    Clabel->setStyleSheet("QLabel{border-image:url(:/cover.jpg);}");
    Clabel->setGeometry(0,0,MX*Label_Size,MY*Label_Size);
    start1=new QPushButton(this);
    start1->setGeometry(MX * Label_Size / 2-120 ,MY * Label_Size / 2,240,120);
    start1->setStyleSheet("QPushButton{border-image:url(:/m1.png);}");
    start2=new QPushButton(this);
    start2->setGeometry(MX * Label_Size /2-120,MY * Label_Size / 2+140,240,120);
    start2->setStyleSheet("QPushButton{border-image:url(:/m2.png);}");
    start3=new QPushButton(this);
    start3->setGeometry(MX * Label_Size / 2 -120,MY * Label_Size / 2+280,240,120);
    start3->setStyleSheet("QPushButton{border-image:url(:/m3.png);}");
    setting=new QPushButton(this);
    setting->setStyleSheet("QPushButton{border-image:url(:/setting.png);}");
    setting->setGeometry(4*MX/5*Label_Size,MY*Label_Size,2*Label_Size,2*Label_Size);
    QObject::connect(start1,SIGNAL(clicked()),this,SLOT(startgame1()));
    QObject::connect(start2,SIGNAL(clicked()),this,SLOT(startgame2()));
    QObject::connect(start3,SIGNAL(clicked()),this,SLOT(startgame3()));
    QObject::connect(setting,SIGNAL(clicked()),this,SLOT(settingslot()));
    Return=new QPushButton(this);
    Replay=new QPushButton(this);
    clock1=new QLabel(this);
    clock2=new QLabel(this);
    Return->setGeometry(0,MY*Label_Size,2*Label_Size,2*Label_Size);
    Return->setStyleSheet("QPushButton{border-image:url(:/return.png);}");
    Replay->setGeometry((MX-2)*Label_Size,MY*Label_Size,2*Label_Size,2*Label_Size);
    Replay->setStyleSheet("QPushButton{border-image:url(:/replay.png);}");
    clock1->setGeometry((2*MX/5-2)*Label_Size,MY*Label_Size,2*Label_Size,2*Label_Size);
    clock2->setGeometry(3*MX*Label_Size/5,MY*Label_Size,2*Label_Size,2*Label_Size);
    clock1->setStyleSheet("QLabel{border-image:url(:/time.png);}");
    clock2->setStyleSheet("QLabel{border-image:url(:/time.png);}");
    Return->hide();
    Return->setDisabled(true);
    Replay->hide();
    Replay->setDisabled(true);
    clock1->hide();
    clock1->setDisabled(true);
    clock2->hide();
    clock2->setDisabled(true);
    time=new QLCDNumber(this);
    time->setMode(QLCDNumber::Dec);
    time->setDigitCount(4);
    time->setGeometry((MX/2-1)*Label_Size,MY*Label_Size,2*Label_Size,2*Label_Size);
    time->setStyleSheet("font:50;color:red;");
    time->setSegmentStyle(QLCDNumber::Flat);
    time->hide();
    counttimer=new QTimer(this);
    QObject::connect(counttimer,SIGNAL(timeout()),this,SLOT(updatetimer()));
    QObject::connect(Return,SIGNAL(clicked()),this,SLOT(returnhome()));
    QObject::connect(Replay,SIGNAL(clicked()),this,SLOT(replay()));
    mousegif=new QMovie(":/mouse1.gif");
    QSize s1(Label_Size+5,Label_Size+5);
    mousegif->setScaledSize(s1);
    allsquare=new square**[MX];
        for(int i=0;i<MX;i++)
        {
            allsquare[i]=new square*[MY];
            for (int j=0;j<MY;j++)
            {
                allsquare[i][j]=new square;
                allsquare[i][j]->X=i;
                allsquare[i][j]->Y=j;
                allsquare[i][j]->label=new QLabel(this);
                allsquare[i][j]->label->setGeometry(i*Label_Size,j*Label_Size,Label_Size,Label_Size);
                allsquare[i][j]->label->hide();
            }
        }
     mouse=allsquare[1][1];
     food=allsquare[MX-2][MY-2];
}
void maze::startgame1()
{
    initgame();
    gametime =MX*MY*0.2;
    updatetimer();
    counttimer->start(1000);
    time->show();
}
void maze::initgame()//初始化游戏界面
{
    Clabel->hide();
    Clabel->setDisabled(true);
    start1->hide();
    start1->setDisabled(true);
    start2->hide();
    start2->setDisabled(true);
    start3->hide();
    start3->setDisabled(true);
    setting->hide();
    setting->setDisabled(true);
    Return->show();
    Replay->show();
    clock1->show();
    clock2->show();
    Return->setDisabled(false);
    Replay->setDisabled(false);
    clock1->setDisabled(false);
    clock2->setDisabled(false);
    //铺地板，铺墙
    structface();
}
void maze::returnhome()//返回主界面
{
    for(int i=0;i<MX;i++)
    {
        for (int j=0;j<MY;j++)
        {
            allsquare[i][j]->label->hide();
        }
    }
    wall.clear();
    ground.clear();
    Return->hide();
    Return->setDisabled(true);
    Replay->hide();
    Replay->setDisabled(true);
    clock1->hide();
    clock1->setDisabled(true);
    clock2->hide();
    clock2->setDisabled(true);
    Clabel->show();
    Clabel->setDisabled(false);
    start1->show();
    start1->setDisabled(false);
    start2->show();
    start2->setDisabled(false);
    start3->show();
    start3->setDisabled(false);
    setting->show();
    setting->setDisabled(false);
    time->hide();
    counttimer->stop(); 
}
void maze::replay()//重玩
{
    gametime =MX*MY*0.2;
    updatetimer();
    counttimer->start(1000);
    wall.clear();
    ground.clear();
    structface();
}
void maze::startgame2()
{

}
void maze::startgame3()
{

}
void maze::structface()
{
    for(int i=0;i<MX;i=i+2)
        {
            for(int j=0;j<MY;j=j+1)
            {
                allsquare[i][j]->type=wall_label;
                allsquare[i][j]->label->setStyleSheet("QLabel{border-image:url(:/wall.jpg)}");
                allsquare[i][j]->label->show();
                wall.append(allsquare[i][j]);
            }
        }

    for(int i=1;i<MX;i=i+2)
    {
        for (int j=0;j<MY;j=j+2)
        {
            allsquare[i][j]->type=wall_label;
            allsquare[i][j]->label->setStyleSheet("QLabel{border-image:url(:/wall.jpg)}");
            allsquare[i][j]->label->show();
            wall.append(allsquare[i][j]);
        }
    }
    int counter=0;
    for(int i=1;i<MX;i=i+2)
    {
        for (int j=1;j<MY;j=j+2)
        {
            allsquare[i][j]->type=ground_label;
            allsquare[i][j]->path=counter;
            allsquare[i][j]->label->setStyleSheet("QLabel{border-image:url(:/diban.jpg)}");
            allsquare[i][j]->label->show();
            ground.append(allsquare[i][j]);
            counter++;
        }
    }
    mouse->label->setMovie(mousegif);
    mousegif->start();
    mouse->type=mouse_label;
    food->label->setStyleSheet("QLabel{border-image:url(:/cheese.jpg)}");
    food->type=food_label;
}
void maze::settingslot()//设置地图大小的函数，这个函数还没写完，先别修改-by lixin.
{
  QDialog* setwindowsize=new QDialog(this);
  setwindowsize->setWindowTitle("修改难度");
  QPushButton* save=new QPushButton (setwindowsize);
  QPushButton* cancle=new QPushButton(setwindowsize);
  QSlider* L=new QSlider (setwindowsize);
  QSlider* W=new QSlider (setwindowsize) ;
  setwindowsize->resize(400,400);
  save->setGeometry(50,300,100,50);
  cancle->setGeometry(250,300,100,50);
  L->setOrientation(Qt::Horizontal);
  W->setOrientation(Qt::Horizontal);
  L->setGeometry(30,50,300,50);
  W->setGeometry(30,100,100,50);
  L->setRange(11,51);
  L->setSingleStep(2);
  W->setRange(15,31);
  W->setSingleStep(2);
  L->setValue(MX);
  W->setValue(MY);
}
void maze::keyPressEvent(QKeyEvent *event)//键盘控制部分
{
    switch (event->key())
    {
    case Qt::Key_Up:
        dx=0;
        dy=1;
        movemouse();
        break;
    case Qt::Key_Down:
        dx=0;
        dy=-1;
        movemouse();
        break;
    case Qt::Key_Left:
        dx=-1;
        dy=0;
        movemouse();
        break;
    case Qt::Key_Right:
        dx=1;
        dy=0;
        movemouse();
        break;
    }
}
void maze::movemouse()//响应键盘的移动函数，要有必要的判断，判断是否有墙
{

}
void maze::destructwall()//构造地图会用到的函数
{

}
void maze::updatetimer()//主要负责显示时间
{
    gametime--;
    QString str;
   if(gametime<100&&gametime>=10){str="00"+QString::number(gametime);}
   if(gametime<10&&gametime>=0){str="000"+QString::number(gametime);}
   if(gametime>100){str="0"+QString::number(gametime);}
   time->display(str);
   if(gametime==0){gameover();}
}
void maze::gameover()
{
    counttimer->stop();
    //接下来可以做游戏结束界面，记得，先删除当前界面,除了下方栏；
}

maze::~maze()
{
    delete ui;
}

