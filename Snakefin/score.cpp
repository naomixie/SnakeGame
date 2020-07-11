#include "score.h"
#include <QFont>

Score::Score()
{
    points = 0;
    setPos(30,20);
    setPlainText("Score:"+QString::number(points));
    setVisible(false);
    setZValue(100);

    QFont sf("Arial",35);
    sf.setBold(true);
    setFont(sf);
    setDefaultTextColor(Qt::white);
}

void Score::setscore(int newscore)
{
    points = newscore;
}

void Score::refreshScore()
{
    setPlainText("Score:"+QString::number(points));
}


