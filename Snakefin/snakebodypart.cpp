#include "snakebodypart.h"
#include "gameconsole.h"
#include "bug.h"

extern gameconsole *game;

//constructor always constructs the tail of the snake
snakeBodyPart::snakeBodyPart(int nx,int ny, QString ndir, QString spart, QGraphicsItem *parent):QGraphicsPixmapItem (parent)
{
    //general settings
    x = nx;
    y = ny;
    direction = ndir;
    part = spart;
    next = nullptr;
    prev = nullptr;

    setPos(x,y);
    setPic();
}

QString snakeBodyPart::checkCollidingObjects()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        fruit *f = dynamic_cast<fruit *>(colliding_items[i]);
        star *s = dynamic_cast<star *>(colliding_items[i]);
        brick *b = dynamic_cast<brick *>(colliding_items[i]);
        bug *bug = dynamic_cast<class bug *>(colliding_items[i]);
        if (f){
        game->gamescene->removeItem(f);
        game->gameScore->setscore(game->gameScore->points+f->point);
        game->gameScore->refreshScore();
        game->eatfruit->play();
        return "fruit";
        }
        else if(bug){
            game->gamescene->removeItem(bug);
            return "bug";
        }
        else if(s && game->snake->head->next != game->snake->tail && game->snakke->head->next!=game->snakke->tail){
        game->gamescene->removeItem(s);
        game->star->play();
        return "star";
        }
        else if(b){
            game->hitwall->play();
            if((game->snake->hearts->number <= 1) || (game->snakke->hearts->number <= 1)){
                game->gameOver();
            }
            else{
                return "sub";
            }
        }
        else if (typeid(*(colliding_items[i])) == typeid (snakeBodyPart)){
            if(game->snake->hearts->number <= 1 || game->snakke->hearts->number <= 1){
                game->gameOver();
            }
            else {
                return "sub";
            }
        }

    }
    return "nothing";

}


void snakeBodyPart::setPic()
{
    //only occurs once because there's only one head
    if(part == "head") {
        if(direction == "l") setPixmap(QPixmap(":/images/head-left.png").scaled(SIZE,SIZE));
        else if(direction == "r") setPixmap(QPixmap(":/images/head-right.png").scaled(SIZE,SIZE));
        else if(direction == "u") setPixmap(QPixmap(":/images/head-up.png").scaled(SIZE,SIZE));
        else if(direction == "d") setPixmap(QPixmap(":/images/head-down.png").scaled(SIZE,SIZE));
    }
    else if(part == "body") setPixmap(QPixmap(":/images/newbody.png").scaled(SIZE,SIZE));
    else if (part == "tail") {
        setPixmap(QPixmap(":/images/tail.png").scaled(SIZE,SIZE));
        }

}

void snakeBodyPart::setpic2()
{
    if(part == "head") {
            if(direction == "l") setPixmap(QPixmap(":/images/snaket_head_left.png").scaled(SIZE,SIZE));
            else if(direction == "r") setPixmap(QPixmap(":/images/snaket_head_right.png").scaled(SIZE,SIZE));
            else if(direction == "u") setPixmap(QPixmap(":/images/snaket_head_up.png").scaled(SIZE,SIZE));
            else if(direction == "d") setPixmap(QPixmap(":/images/snaket_head_down.png").scaled(SIZE,SIZE));
        }
        else if(part == "body") setPixmap(QPixmap(":/images/snaket_body.png").scaled(SIZE,SIZE));
        else if (part == "tail") {
            setPixmap(QPixmap(":/images/snaket_tail.png").scaled(SIZE,SIZE));
            }

}


