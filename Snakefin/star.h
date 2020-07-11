#ifndef STAR_H
#define STAR_H
#include <QGraphicsPixmapItem>
#include <QTimer>


class star : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    QTimer *timer;
    int x;
    int y;
    int SIZE = 50;
    star(QGraphicsItem *parent= NULL);
    void checkCollidingObjects();

public slots:
    void refreshPosition();
};
#endif // STAR_H
