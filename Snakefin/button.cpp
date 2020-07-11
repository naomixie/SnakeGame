#include "button.h"
#include <QBrush>
#include <QFont>

button::button(QString text, QGraphicsItem *parent)
    :QGraphicsRectItem (parent)
{
    //confugure the button
    setRect(0,0,250,60);
    QBrush bb;
    bb.setColor(Qt::darkRed);
    bb.setStyle(Qt::SolidPattern);
    setBrush(bb);

    buttonText = new QGraphicsTextItem(text,this);
    buttonText->setDefaultTextColor(Qt::white);
    QFont bf("Arial",18);
    buttonText->setFont(bf);

    resetButtonText();

    //hover responses
    setAcceptHoverEvents(true);
    //setAcceptedMouseButtons(Qt::LeftButton);

}

void button::resetButtonText()
{
    int xPos = rect().width()/2 - buttonText->boundingRect().width()/2 ;
    int yPos = rect().height()/2 - buttonText->boundingRect().height()/2;
    buttonText->setPos(xPos,yPos);

}


void button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
        QBrush hb;
        hb.setStyle(Qt::SolidPattern);
        hb.setColor(Qt::darkYellow);
        setBrush(hb);
}

void button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
        QBrush hb;
        hb.setStyle(Qt::SolidPattern);
        hb.setColor(Qt::darkRed);
        setBrush(hb);
}

void button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
        emit clicked();
}
