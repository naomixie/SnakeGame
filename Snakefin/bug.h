#ifndef BUG_H
#define BUG_H
#include <QGraphicsPixmapItem>
#include <QTimer>

class bug:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    QTimer *timer;
    int x;
    int y;
    int SIZE = 50;
    bug(QGraphicsItem *parent= NULL);
    void checkCollidingObjects();

public slots:

    void refreshPosition();

};

#endif // BUG_H
