#include "star.h"
#include "gameconsole.h"
#include "snake.h"

extern gameconsole *game;

star::star(QGraphicsItem *parent):QGraphicsPixmapItem (parent)
{
    timer = new QTimer();

    refreshPosition();

    setPixmap(QPixmap(":/images/star.png").scaled(SIZE,SIZE));
    timer->start(5000);

    connect(timer,SIGNAL(timeout()),this,SLOT(refreshPosition()));

}


void star::refreshPosition()
{
    game->gamescene->addItem(this);
    x = SIZE+(rand() % (1100/SIZE))*SIZE;
    y = 150+(rand() % (600/SIZE))*SIZE;
    //checkCollidingObjects();
    setPos(x,y);
}

void star::checkCollidingObjects()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid (*(colliding_items[i])) == typeid (fruit) || typeid (*(colliding_items[i])) == typeid (snakeBodyPart) ){
            checkCollidingObjects();
        }
}
}


