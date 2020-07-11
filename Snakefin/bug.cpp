#include "bug.h"
#include "gameconsole.h"
#include "snake.h"

extern gameconsole *game;


void bug::refreshPosition()
{
    game->gamescene->addItem(this);
    x = SIZE+(rand() % (1100/SIZE))*SIZE;
    y = 150+(rand() % (600/SIZE))*SIZE;
    //checkCollidingObjects();
    setPos(x,y);
}

void bug::checkCollidingObjects()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid (*(colliding_items[i])) == typeid (fruit) || typeid (*(colliding_items[i])) == typeid (snakeBodyPart) ){
            checkCollidingObjects();
        }
    }
}


bug::bug(QGraphicsItem *parent):QGraphicsPixmapItem (parent)
{
    timer = new QTimer();

    refreshPosition();

    setPixmap(QPixmap(":/images/bug.png").scaled(SIZE,SIZE));
    timer->start(4000);
    connect(timer,SIGNAL(timeout()),this,SLOT(refreshPosition()));
}
