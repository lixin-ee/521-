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
}
void maze::startgame1()
{
    initgame();
    gametime =MX*MY*0.2;
       time=new QLCDNumber(this);
       time->setMode(QLCDNumber::Dec);
       time->setDigitCount(4);
       time->setGeometry((MX/2-1)*Label_Size,MY*Label_Size,2*Label_Size,2*Label_Size);
       time->setStyleSheet("font:50;color:red;");
       time->setSegmentStyle(QLCDNumber::Flat);
       time->show();
       counttimer=new QTimer(this);
       counttimer->start(1000);
       QObject::connect(counttimer,SIGNAL(timeout()),this,SLOT(updatetimer()));

}
void maze::initgame()
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
    Return->show();
    Replay->show();
    clock1->show();
    clock2->show();
    //铺地板，铺墙


}
void maze::returnhome()
{
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

}
void maze::replay()
{
    initgame();
}
void maze::startgame2()
{

}
void maze::startgame3()
{

}
void maze::settingslot()
{

}
void maze::keyPressEvent(QKeyEvent *event)
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
void maze::movemouse()
{

}
void maze::destructwall()
{

}
void maze::updatetimer()
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
}

maze::~maze()
{
    delete ui;
}
