#include "snaket.h"
#include <QDebug>
#include "gameconsole.h"

extern gameconsole *game;


snaket::snaket(int sx,int sy,QGraphicsItem *parent):QGraphicsRectItem (parent)
{
    head = new snakeBodyPart(sx,sy,"l","head",this);
    head->setpic2();
    tail = new snakeBodyPart(sx+SIZE,sy,"l","tail",this);
    tail->setpic2();
    head->next = tail;
    tail->prev = head;
    addBodyPart();
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setZValue(1);
    //addBodyPart();
    hearts = new hh(this);
    hearts->setPos(100,20);
    timer = new QTimer();
    timer2 = new QTimer();
    timer->start(400);

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
}

void snaket::addBodyPart()
{
    snakeBodyPart *newPart = new snakeBodyPart(tail->x, tail->y,tail->direction,"tail",this);
    if(tail->direction == "l") newPart->x = newPart->x+SIZE;
    else if(tail->direction == "r") newPart->x = newPart->x-SIZE;
    else if(tail->direction == "u") newPart->y = newPart->y+SIZE;
    else if(tail->direction == "d") newPart->y = newPart->y-SIZE;
    tail->next = newPart;
    newPart->prev = tail;
    tail->part = "body";
    tail->setpic2();
    tail = newPart;
    tail->setPos(tail->x,tail->y);
    tail->setpic2();
}

void snaket::removeBodyPart()
{
    snakeBodyPart *newPart = new snakeBodyPart();
    if(tail->direction == "l") tail->x = tail->x-SIZE;
    else if(tail->direction == "r") tail->x = tail->x+SIZE;
    else if(tail->direction == "u") tail->y = tail->y-SIZE;
    else if(tail->direction == "d") tail->y = tail->y+SIZE;
    newPart = tail;
    tail = newPart->prev;
    newPart -> prev = NULL;
    tail -> next = NULL;
    tail->part = "tail";
    delete newPart;
}

void snaket::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "my rect knows you pressed a key! :D";
    if(event->key() == Qt::Key_A && head->direction !="r") {
        head->direction = "l";
    }
    else if(event->key() == Qt::Key_D && head->direction !="l") {
        head->direction = "r";
        }
    else if(event->key() == Qt::Key_W && head->direction !="d") {
        head->direction = "u";
        }
    else if(event->key() == Qt::Key_S && head->direction !="u") {
        head->direction = "d";
    }
}


void snaket::move()
{
    //if(AIMModeOn == 0) AIMMode();

    snakeBodyPart *temp1 = new snakeBodyPart();
    snakeBodyPart *temp2 = new snakeBodyPart() ;

    for (temp1 = head;temp1;temp1 = temp1->next) {

        if(temp1 == head ) {
            QString message = temp1->checkCollidingObjects();
            if(message == "sub") {
                hearts->number-- ;
                hearts->setpic();
                game->resetround();
            }
            else if(message == "fruit"){
                addBodyPart();
                //AIMModeOn=1;
            }
            else if(message == "star"){
                timer->stop();
                removeBodyPart();
                timer->start();
            }
            else if(message == "bug"){
                timer2->start(4000);
                timer->start(200);
            }
        }

        if(temp1->direction == "l") temp1->x = temp1->x - SIZE;
        else if(temp1->direction == "r") temp1->x = temp1->x + SIZE;
        else if(temp1->direction == "u") temp1->y = temp1->y - SIZE;
        else if(temp1->direction == "d") temp1->y = temp1->y + SIZE;

        if(temp1->y >= 800) temp1->y = 0;
        else if(temp1->y < 0) temp1->y = 800 - SIZE;
        else if(temp1->x >= 1200) temp1->x = 0;
        else if(temp1->x < 0) temp1->x = 1200 - SIZE;
        temp1->setPos(temp1->x,temp1->y);
        temp1->setpic2();
    }

    for(temp2 = tail;temp2!=head;temp2=temp2->prev){
        temp2->direction = temp2->prev->direction;
    }

}
