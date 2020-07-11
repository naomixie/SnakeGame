#include "drawfruit.h"

drawfruit::drawfruit(QGraphicsItem *parent): QGraphicsRectItem (parent)
{
    ber = new fruit(this,"bug");

    //connect(berry,SIGNAL(timeout()),this,SLOT(drawBerry()));
    connect(ber->timer,SIGNAL(timeout()),this,SLOT(drawBerry()));
}

void drawfruit::drawBerry()
{
    ber->refreshPosition();
}

void drawfruit::removeBerry()
{

}

