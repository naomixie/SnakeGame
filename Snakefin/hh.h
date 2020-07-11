#ifndef HH_H
#define HH_H


#include <qgraphicsitem.h>
#include <QGraphicsPixmapItem>

class hh : public QGraphicsPixmapItem
{
public:
    int number;
    int SIZE = 50;
    hh(QGraphicsItem *parent = 0);
    void setpic();
};


#endif // HH_H
