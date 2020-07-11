#ifndef BRICK_H
#define BRICK_H

#include <QObject>
#include <QGraphicsPixmapItem>

class brick:public QGraphicsPixmapItem
{
public:
    int x,y;
    brick *next;
    brick *prev;
    int SIZE = 50;
    brick(int nx,int ny,QGraphicsItem *parent);
};

#endif // BRICK_H
