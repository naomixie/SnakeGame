#ifndef SNAKE_H
#define SNAKE_H

#include "snakebodypart.h"
#include "brick.h"
#include "fruit.h"
#include "hh.h"
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include <QGraphicsRectItem>

//SX,SY IS THE INITIAL LOCATION FOR THE SNAKE

class Snake : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    bool AIMModeOn = 1;
    QTimer *timer,*timer2;
    int SIZE = 50;
    brick *wall;
    hh *hearts;
    snakeBodyPart *head,*tail;
    Snake(int sx, int sy, QGraphicsItem *parent = 0);
    void changeDirection();//CHANGING THE DIRECTION OF ALL BODY PARTS
    void addBodyPart();
    void removeBodyPart();
    void keyPressEvent(QKeyEvent *event);
    void AIMMode();
    void checkCollidingObjects();
    double distance(int x, int y,int a, int b);
public slots:
    void move();
    void resetSpeed();
};

#endif // SNAKE_H
