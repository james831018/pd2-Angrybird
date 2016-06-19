#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>

#include <Box2D/Box2D.h>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QCursor>
#include <QDesktopWidget>
#include <QTimer>
#include <QMouseEvent>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <iostream>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <barrier.h>
#include <slingshot.h>
#include <yello_bird.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    void restart();

signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    Bird *birdie[5];
    //Bird *fuck;
    void keyPressEvent(QKeyEvent *event);
    int beginx,beginy,endx,endy,diffx,diffy,right,righty;
    int whichbird=1;
    int getvelocityx,getvelocityy;
    barrier *verbarrier[4];
    int pigexist;
    int score;
    int ifskill;
};

#endif // MAINWINDOW_H
