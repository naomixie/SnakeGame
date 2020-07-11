#ifndef SNAKET_H
#define SNAKET_H

#include "snakebodypart.h"
#include "brick.h"
#include "fruit.h"
#include "hh.h"
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include <QGraphicsRectItem>

class snaket : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    QTimer *timer,*timer2;
    int SIZE = 50;
    brick *wall;
    hh *hearts;
    snakeBodyPart *head,*tail;
    snaket(int sx, int sy, QGraphicsItem *parent = 0);
    void changeDirection();//CHANGING THE DIRECTION OF ALL BODY PARTS
    void addBodyPart();
    void removeBodyPart();
    void keyPressEvent(QKeyEvent *event);
    void checkCollidingObjects();
public slots:
    void move();
};
#endif // SNAKET_H
