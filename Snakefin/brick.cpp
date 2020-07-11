#include "brick.h"

brick::brick(int nx, int ny, QGraphicsItem *parent):QGraphicsPixmapItem (parent)
{
    next = nullptr;
    prev = nullptr;
    x = nx;
    y = ny;
    setPixmap(QPixmap(":/images/brick.png").scaled(SIZE,SIZE));
    setPos(x,y);
}
