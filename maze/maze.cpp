#include "maze.h"
#include "ui_maze.h"
maze::maze(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::maze)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/tubiao.ico"));
    setWindowTitle("maze521");
    Clabel=new QLabel(this);
    start1=new QPushButton(this);
    start2=new QPushButton(this);
    start3=new QPushButton(this);
    setting=new QPushButton(this);
    resizewindow();
    QObject::connect(start1,SIGNAL(clicked()),this,SLOT(startgame1()));
    QObject::connect(start2,SIGNAL(clicked()),this,SLOT(startgame2()));
    QObject::connect(start3,SIGNAL(clicked()),this,SLOT(startgame3()));
    QObject::connect(setting,SIGNAL(clicked()),this,SLOT(settingslot()));
    mousegif=new QMovie(":/mouse1.gif");
    QSize s1(Label_Size+5,Label_Size+5);
    mousegif->setScaledSize(s1);       
}
void maze::startgame1()
{
    initgame();
    gametime =MX*MY*0.2;
    updatetimer();
    counttimer=new QTimer(this);
    QObject::connect(counttimer,SIGNAL(timeout()),this,SLOT(updatetimer()));
    counttimer->start(1000);
    time->show();

}
void maze::initgame()//初始化游戏界面
{

    Clabel->hide();
    Clabel->setDisabled(true);
    setting->hide();
    setting->setDisabled(true);
    start1->hide();
    start1->setDisabled(true);
    start2->hide();
    start2->setDisabled(true);
    start3->hide();
    start3->setDisabled(true);
    Return=new QPushButton(this);
    Replay=new QPushButton(this);
    Replay->setFocusPolicy(Qt::NoFocus);
    clock1=new QLabel(this);
    clock2=new QLabel(this);
    time=new QLCDNumber(this);
    Return->setGeometry(0,MY*Label_Size,2*Label_Size,2*Label_Size);
    Return->setStyleSheet("QPushButton{border-image:url(:/return.png);}");
    Replay->setGeometry((MX-2)*Label_Size,MY*Label_Size,2*Label_Size,2*Label_Size);
    Replay->setStyleSheet("QPushButton{border-image:url(:/replay.png);}");
    clock1->setGeometry((2*MX/5-2)*Label_Size,MY*Label_Size,2*Label_Size,2*Label_Size);
    clock2->setGeometry(3*MX*Label_Size/5,MY*Label_Size,2*Label_Size,2*Label_Size);
    clock1->setStyleSheet("QLabel{border-image:url(:/time.png);}");
    clock2->setStyleSheet("QLabel{border-image:url(:/time.png);}");
    Return->show();
    Replay->show();
    clock1->show();
    clock2->show();
    time->setMode(QLCDNumber::Dec);
    time->setDigitCount(4);
    time->setGeometry((MX/2-1)*Label_Size,MY*Label_Size,2*Label_Size,2*Label_Size);
    time->setStyleSheet("font:50;color:red;");
    time->setSegmentStyle(QLCDNumber::Flat);
    time->show();
    QObject::connect(Return,SIGNAL(clicked()),this,SLOT(returnhome()));
    QObject::connect(Replay,SIGNAL(clicked()),this,SLOT(replay()));
    //铺地板，铺墙
    structface();
}
void maze::returnhome()//返回主界面
{
    wall.clear();
    ground.clear();
    for(int i=0;i<MX;i++)
    {
        for (int j=0;j<MY;j++)
        {
           delete allsquare[i][j]->label;
           delete allsquare[i][j];

        }
    } 
    Clabel->show();
    Clabel->setDisabled(false);
    setting->show();
    setting->setDisabled(false);
    start1->show();
    start1->setDisabled(false);
    start2->show();
    start2->setDisabled(false);
    start3->show();
    start3->setDisabled(false);
    delete counttimer;
    delete Return;
    delete Replay;
    delete time;
    delete clock1;
    delete clock2;
}
void maze::replay()//重玩
{
    gametime =MX*MY*0.2;
    updatetimer();
    counttimer->start(1000);
    mouse->label->clear();
    mouse->type=ground_label;
    allsquare[1][1]->type=mouse_label;
    mouse=allsquare[1][1];
    mouse->label->setMovie(mousegif);
    mousegif->start();
}
void maze::startgame2()
{

}
void maze::startgame3()
{

}
void maze::structface()
{
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
        }
    }
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
           /* allsquare[i][j]->type=wall_label;
            allsquare[i][j]->label->setStyleSheet("QLabel{border-image:url(:/wall.jpg)}");
            allsquare[i][j]->label->show();
            wall.append(allsquare[i][j]);*/
            allsquare[i][j]->type=ground_label;
            allsquare[i][j]->label->setStyleSheet("QLabel{border-image:url(:/diban.jpg)}");
            allsquare[i][j]->label->show();
            ground.append(allsquare[i][j]);
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
    mouse=allsquare[1][1];
    food=allsquare[MX-2][MY-2];
    mouse->label->setMovie(mousegif);
    mousegif->start();
    mouse->type=mouse_label;
    food->label->setStyleSheet("QLabel{border-image:url(:/cheese.jpg)}");
    food->type=food_label;
}
void maze::settingslot()//设置地图大小的函数
{
  QDialog* setwindowsize=new QDialog(this);
  setwindowsize->setWindowTitle("修改难度");
  QPushButton*save=new QPushButton ("ok",setwindowsize);
  QPushButton*cancle=new QPushButton("cancle",setwindowsize);
  QSlider* L=new QSlider (setwindowsize);
  QSlider* W=new QSlider (setwindowsize) ;
  QLabel* length=new QLabel(setwindowsize);
  QLabel* width=new QLabel (setwindowsize);
  length->setText("长度:");
  width->setText("宽度:");
  length->setGeometry(30,50,40,40);
  width->setGeometry(30,100,40,40);
  setwindowsize->resize(400,400);
  save->setGeometry(50,300,100,50);
  cancle->setGeometry(250,300,100,50);
  L->setOrientation(Qt::Horizontal);
  W->setOrientation(Qt::Horizontal);
  L->setGeometry(60,50,300,50);
  W->setGeometry(60,100,100,50);
  L->setRange(11,51);
  L->setSingleStep(2);
  W->setRange(15,31);
  W->setSingleStep(2);
  L->setValue(MX);
  W->setValue(MY);
  QObject::connect(save,SIGNAL(clicked()),setwindowsize,SLOT(accept()));
  QObject::connect(cancle,SIGNAL(clicked()),setwindowsize,SLOT(reject()));
  if(setwindowsize->exec()==QDialog::Accepted)
  {
      MX=L->value();MY=W->value();
      resizewindow();
  }
  delete W;
  delete L;
  delete save;
  delete cancle;
  delete length;
  delete width;
  delete setwindowsize;
}
void maze::keyPressEvent(QKeyEvent *event)//键盘控制部分
{
    switch (event->key())
    {
    case Qt::Key_Up:
        dx=0;
        dy=-1;
        movemouse();
        break;
    case Qt::Key_Down:
        dx=0;
        dy=1;
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
    square* tempMouse=allsquare[mouse->X+dx][mouse->Y+dy];//设置临时的指针，先让老鼠移动在判断是否有墙

        if(tempMouse->type==wall_label)//如果老鼠撞到了墙
        {

        }
        else//如果老鼠没有撞到墙
        {
            if(tempMouse->type==food_label)
                gameover();
            else
                {
                tempMouse->type=mouse_label;
                allsquare[mouse->X][mouse->Y]->type=ground_label;
                allsquare[mouse->X][mouse->Y]->label->clear();
                allsquare[mouse->X][mouse->Y]->label->setStyleSheet("QLabel{border-image:url(:/diban.jpg)}");
                allsquare[mouse->X][mouse->Y]->label->show();
                allsquare[mouse->X+dx][mouse->Y+dy]->type=mouse_label;
                allsquare[mouse->X+dx][mouse->Y+dy]->label->setMovie(mousegif);
                mousegif->start();
                mouse=tempMouse;
            }


        }

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

    //接下来可以做游戏结束界面，记得，先删除当前界面,除了下方栏；
}



void maze::resizewindow()
{

    resize((MX)*Label_Size,(MY+2)*Label_Size);
    Clabel->setStyleSheet("QLabel{border-image:url(:/cover.jpg);}");
    Clabel->setGeometry(0,0,MX*Label_Size,MY*Label_Size);
    start1->setGeometry(MX * Label_Size / 2-120 ,MY * Label_Size / 2,240,120);
    start1->setStyleSheet("QPushButton{border-image:url(:/m1.png);}");
    start2->setGeometry(MX * Label_Size /2-120,MY * Label_Size / 2+140,240,120);
    start2->setStyleSheet("QPushButton{border-image:url(:/m2.png);}");
    start3->setGeometry(MX * Label_Size / 2 -120,MY * Label_Size / 2+280,240,120);
    start3->setStyleSheet("QPushButton{border-image:url(:/m3.png);}");
    setting->setStyleSheet("QPushButton{border-image:url(:/setting.png);}");
    setting->setGeometry(4*MX/5*Label_Size,MY*Label_Size,2*Label_Size,2*Label_Size);
}
maze::~maze()
{
    delete ui;
    delete setting;
    delete Clabel;
    delete start1;
    delete start2;
    delete start3;
}

