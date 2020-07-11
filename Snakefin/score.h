#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>


class Score:public QGraphicsTextItem
{
public:
    int points;
    Score();
    void setscore(int newscore);
    void refreshScore();

};

#endif // SCORE_H
