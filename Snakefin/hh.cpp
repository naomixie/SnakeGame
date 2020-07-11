#include "hh.h"

hh::hh(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    number = 3;
    setPos(900,20);
    setpic();
}

void hh::setpic()
{
    if(number == 3){
        setPixmap(QPixmap(":/images/threeheart.png").scaled(SIZE*3,SIZE));
    }
    else if (number == 2){
        setPixmap(QPixmap(":/images/twoheart.png").scaled(SIZE*2,SIZE));
    }
    else if (number == 1){
        setPixmap(QPixmap(":/images/hearty.png").scaled(SIZE,SIZE));
    }
}

