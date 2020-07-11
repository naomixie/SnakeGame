#include "snake.h"
#include <QDebug>
#include "gameconsole.h"
#include <cmath>

extern gameconsole *game;


Snake::Snake(int sx,int sy,QGraphicsItem *parent):QGraphicsRectItem (parent)
{
    head = new snakeBodyPart(sx,sy,"l","head",this);
    tail = new snakeBodyPart(sx+SIZE,sy,"l","tail",this);
    head->next = tail;
    tail->prev = head;
    addBodyPart();
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setZValue(1);
    hearts = new hh(this);
    //addBodyPart();
    timer = new QTimer();
    timer2 = new QTimer();
    timer->start(400);

    connect(timer2,SIGNAL(timeout()),this,SLOT(resetSpeed()));
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
}

void Snake::addBodyPart()
{
    snakeBodyPart *newPart = new snakeBodyPart(tail->x, tail->y,tail->direction,"tail",this);
    if(tail->direction == "l") newPart->x = newPart->x+SIZE;
    else if(tail->direction == "r") newPart->x = newPart->x-SIZE;
    else if(tail->direction == "u") newPart->y = newPart->y+SIZE;
    else if(tail->direction == "d") newPart->y = newPart->y-SIZE;
    tail->next = newPart;
    newPart->prev = tail;
    tail->part = "body";
    tail->setPic();
    tail = newPart;
    tail->setPos(tail->x,tail->y);
    tail->setPic();
}

void Snake::removeBodyPart()
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


void Snake::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "my rect knows you pressed a key! :D";
    if(event->key() == Qt::Key_Left && head->direction !="r") {
        head->direction = "l";
        AIMModeOn = 1;
    }
    else if(event->key() == Qt::Key_Right && head->direction !="l") {
        head->direction = "r";
        AIMModeOn = 1;
        }
    else if(event->key() == Qt::Key_Up && head->direction !="d") {
        head->direction = "u";
        AIMModeOn = 1;
        }
    else if(event->key() == Qt::Key_Down && head->direction !="u") {
        head->direction = "d";
        AIMModeOn = 1;
    }
    else if(event->key() == Qt::Key_M){
        AIMModeOn = 0;
    }
}

void Snake::AIMMode()
{
    double dis1,dis2;
    dis1 = distance(game->mango->x,game->mango->y,head->x,head->y);
    dis2 = distance(game->berry->x,game->berry->y,head->x,head->y);
    int a = head->x, b = head ->y;
    int x,y;
    if(dis1<=dis2){
        x = game->mango->x;
        y = game->mango->y;}
    else {
        x = game->berry->x;
        y = game->berry->y;}
    if(x < a && y < b ){
            if (head->direction == "d") head->direction = "l";
            else if (head->direction == "r") head->direction = "u";
            else return;
        }
        if(x > a && y < b ){
            if (head->direction == "d") head->direction = "r";
            else if (head->direction == "l") head->direction = "u";
            else return;
        }
        if(x < a && y > b ){
            if (head->direction == "u") head->direction = "l";
            else if (head->direction == "r") head->direction = "d";
            else return;
        }
        if(x > a && y > b ){
            if (head->direction == "u") head->direction = "r";
            else if (head->direction == "l") head->direction = "d";
            else return;
        }
        else if (x == a ){
            if(y < b ){
                if(head->direction!="d") head->direction = "u";
                else if(head->direction == "u") return;
                else head->direction = "l";
            }
            else if(y >b ) {
                if(head->direction!="u") head->direction = "d";
                else if(head->direction == "d") return;
                else head->direction = "l";
            }
        }
        else if (y == b ){
            if(x < a ){
                if(head->direction!="r") head->direction = "l";
                else if(head->direction == "l") return;
                else head->direction = "u";
            }
            else if(x > a ) {
                if(head->direction!="l") head->direction = "r";
                else if(head->direction == "r") return;
                else head->direction = "u";
            }
        }
}



double Snake::distance(int x, int y,int a, int b)
{
    return sqrt(((x-a)*(x-a)) + ((y-b)*(y-b)));
}

void Snake::move()
{
    if(AIMModeOn == 0) AIMMode();

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
                AIMModeOn=1;
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
        temp1->setPic();
    }

    for(temp2 = tail;temp2!=head;temp2=temp2->prev){
        temp2->direction = temp2->prev->direction;
    }
}

void Snake::resetSpeed()
{
    timer->start(300);
}


