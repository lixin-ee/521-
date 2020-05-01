#ifndef MAZE_H
#define MAZE_H

#include <QWidget>
#include<QMovie>
#include<QLabel>
#include<QIcon>
#include<QTimer>
#include<QPushButton>
#include<QVector>
#include<QLayout>
#include<QPixmap>
#include<QMovie>
#include<QObject>
#include<QLCDNumber>
#include<QKeyEvent>
#include<QString>
#include<QFont>
#define Label_Size  30
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class maze; }
QT_END_NAMESPACE
enum Label{
    wall_label,cat_label,mouse_label,food_label,ground_label
};
struct square
{
    int type;
    int X;
    int Y;
    int path;
    QLabel *label;
};
class maze : public QWidget
{
    Q_OBJECT

public:
    maze(QWidget *parent = nullptr);

    void gameover();
    void updatetime();
    void returnhome();
    void destructwall();
    void movemouse();
    void movecat();
    void keyPressEvent(QKeyEvent *event);
    ~maze();
private slots:
    //void findpath();
    void startgame1();
    void startgame2();
    void startgame3();
    void replay();
    void initgame();
    void settingslot();
    void updatetimer();
private:
    Ui::maze *ui;
    QPushButton* setting;
    QTimer* counttimer;
    QPushButton* start1;
    QPushButton* start2;
    QPushButton* start3;
    QLabel* Clabel;
    QPushButton* Return;
    QPushButton* Replay;
    QLCDNumber* time;
    QLabel* clock1;
    QLabel* clock2;
    square*cat;
    square*mouse;
    square*food;
    int dx=1;
    int dy=0;
    int MX=40;
    int MY=30;
    int gametime;
    QVector<square*>wall;
    QVector<square*>ground;
};

#endif // MAZE_H
