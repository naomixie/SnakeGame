#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QBrush>

class button : public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    //button();
    QGraphicsTextItem *buttonText;
    button(QString text,QGraphicsItem *parent = NULL);
    void resetButtonText();

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);


signals:
    void clicked();

};

#endif // BUTTON_H
