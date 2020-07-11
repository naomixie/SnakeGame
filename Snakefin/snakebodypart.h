#ifndef SNAKEBODYPART_H
#define SNAKEBODYPART_H

#include <QString>
#include <QObject>
#include <QGraphicsPixmapItem>
/*
 * should have coordinates for moving
 * should have a direcrion indicator
 * indicator for tails
 */

class snakeBodyPart :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    int x,y;
    QString part;
    QString direction;
    snakeBodyPart *next;
    snakeBodyPart *prev;
    int SIZE = 50;
    //constructor for tails
    snakeBodyPart(int nx,int ny,QString ndir,QString spart, QGraphicsItem *parent);
    //general constructor
    snakeBodyPart(){next = nullptr;}
    QString checkCollidingObjects();
    void setPic();
    void setpic2();

};

#endif // SNAKEBODYPART_H
