#ifndef DRAWFRUIT_H
#define DRAWFRUIT_H

#include <QTimer>
#include "fruit.h"


class drawfruit:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    fruit *ber;
    QTimer *berry;
    drawfruit(QGraphicsItem *parent = 0);
public slots:
    void drawBerry();
    void removeBerry();
    //void drawBanana();
    //void drawBug();
};

#endif // DRAWFRUIT_H
