#include "fruit.h"
#include "gameconsole.h"
#include "snake.h"

extern gameconsole *game;


fruit::fruit(QString type, QGraphicsItem *parent):QGraphicsPixmapItem (parent)
{
    timer = new QTimer();

    refreshPosition();

    if(type == "mango"){
        setPixmap(QPixmap(":/images/mango.png").scaled(SIZE,SIZE));
        timer->start(6000);
        point = 50;
    }
    else if(type == "berry"){
        setPixmap(QPixmap(":/images/berry.png").scaled(SIZE,SIZE));
        timer->start(8000);
        point = 20;
    }

    else if(type == "bug"){
        setPixmap(QPixmap(":/images/bug.png").scaled(SIZE,SIZE));
        timer->start(5000);
        point = 100;
    }

    connect(timer,SIGNAL(timeout()),this,SLOT(refreshPosition()));

}

void fruit::checkCollidingObjects()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid (*(colliding_items[i])) == typeid (fruit) || typeid (*(colliding_items[i])) == typeid (snakeBodyPart) ){

        checkCollidingObjects();
        }
}
}

void fruit::refreshPosition()
{
    game->gamescene->addItem(this);
    x = SIZE+(rand() % (1100/SIZE))*SIZE;
    y = 150+(rand() % (600/SIZE))*SIZE;
    //checkCollidingObjects();
    setPos(x,y);

}




