#ifndef WALL_H
#define WALL_H

#include "brick.h"
#include <QObject>
#include <QGraphicsRectItem>


class wall : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    int SIZE = 50;
    wall(int player,int round,QGraphicsItem *parent = 0);
};


#endif // WALL_H
