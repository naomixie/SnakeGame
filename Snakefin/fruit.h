#ifndef FRUIT_H
#define FRUIT_H
#include <QGraphicsPixmapItem>
#include <QTimer>


class fruit :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    QTimer *timer;
    int point;
    int x;
    int y;
    int SIZE = 50;
    fruit(QString type, QGraphicsItem *parent= NULL);
    void checkCollidingObjects();

public slots:
    void refreshPosition();
};

#endif // FRUIT_H
