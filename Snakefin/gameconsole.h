#ifndef GAMECONSOLE_H
#define GAMECONSOLE_H
#include "score.h"
#include "button.h"
#include "snakebodypart.h"
#include "snaket.h"
#include "hh.h"
#include "bug.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QString>
#include <QKeyEvent>
#include "snake.h"
#include "fruit.h"
#include "star.h"
#include "wall.h"
#include <QMediaPlayer>


class gameconsole:public QGraphicsView
{
    Q_OBJECT
public:
    QMediaPlayer *bgmusic = new QMediaPlayer();
    QMediaPlayer *eatfruit = new QMediaPlayer();
    QMediaPlayer *star = new QMediaPlayer();
    QMediaPlayer *hitwall = new QMediaPlayer();
    QTimer *timer,*roundtimer;
    Snake *snake;
    snaket *snakke;
    bug *Bug;
    fruit *berry,*mango;
    bool isPause = 1;
    int player,round = 1;
    class star *byul;
    wall *walls;
    QGraphicsTextItem *Title,*credits,*reminder;
    button *mainButton,*quitButton,*backButton,*dButton;
    Score *gameScore = new Score();
    QGraphicsScene *gamescene;
    gameconsole(QWidget *parent = 0);
    void displayGameOverMenu();
    void addText(QGraphicsTextItem *text,QString ttext, int fontSize,float ypos);
    void keyPressEvent(QKeyEvent *event);
    void gameOver();
    void resetround();
    void resetTwoPlayerRound();
    void pause();

public slots:
    void displayMainMenu();
    void start();
    void start2();
    void playmusic();
    void startNewRound();


};

#endif // GAMECONSOLE_H
