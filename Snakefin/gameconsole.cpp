#include "gameconsole.h"
#include "button.h"
#include <QGraphicsTextItem>
#include <QMediaPlayer>

gameconsole::gameconsole(QWidget *parent)
{
    gamescene = new QGraphicsScene();
    timer = new QTimer;
    timer->start(20000);

    roundtimer = new QTimer;
    //fixing the window
    setFixedSize(1200,800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    Title = new QGraphicsTextItem("Snake Game");
    //set the font
    QFont tf("Arial",50);
    Title->setDefaultTextColor(Qt::darkRed);
    Title->setFont(tf);
    //setting the position
    int xPosT = this->width()/2 - Title->boundingRect().width()/2;
    int yPosT = this->height()/4 ;
    Title->setPos(xPosT,yPosT);

    credits = new QGraphicsTextItem("Music by Eric Matyas -> www.soundimage.org");
    QFont cf("Arial",15);
    credits->setDefaultTextColor(Qt::darkRed);
    credits->setFont(cf);
    int xcPosT = this->width()/2 - credits->boundingRect().width()/2;
    int ycPosT = this->height()*15/16 ;
    credits->setPos(xcPosT,ycPosT);

    mainButton = new button("Play Game");
    //setting the button position
    int xPosB = this->width()*35/100 - mainButton->boundingRect().width()/2;
    int yPosB = this->height()*3/5 - mainButton->boundingRect().height()/2;
    mainButton->setPos(xPosB,yPosB);
    connect(mainButton, SIGNAL(clicked()),this, SLOT(start()));

    dButton = new button("2 Players");
    //setting the button position
    int xdPosB = this->width()*65/100 - dButton ->boundingRect().width()/2;
    int ydPosB = this->height()*3/5 - dButton->boundingRect().height()/2;
    dButton->setPos(xdPosB,ydPosB);
    connect(dButton, SIGNAL(clicked()),this, SLOT(start2()));

    backButton = new button("Back to Main Menu");
    //setting the button position
    int xbPosB = this->width()/2 - backButton->boundingRect().width()/2;
    int ybPosB = this->height()*3/5 - backButton->boundingRect().height()/2;
    backButton->setPos(xbPosB,ybPosB);
    connect(backButton, SIGNAL(clicked()),this, SLOT(displayMainMenu()));

    quitButton = new button("Quit");
    int xqPosB = this->width()/2 - quitButton->boundingRect().width()/2;
    int yqPosB = this->height()*8/10 - quitButton->boundingRect().height()/2;
    quitButton->setPos(xqPosB,yqPosB);
    connect(quitButton, SIGNAL(clicked()),this, SLOT(close()));

    //setting the scene
    gamescene->setSceneRect(0,0,1200,800);
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem();
    QPixmap bg = QPixmap(":/images/back.png");
    background -> setPixmap(bg.scaled(1200,800));
    gamescene->addItem(background);
    setScene(gamescene);

    //adding the score
    gamescene->addItem(gameScore);


    bgmusic->setVolume(60);
    bgmusic->setMedia(QUrl("qrc:/music/Bonkers-for-Arcades.mp3"));
    bgmusic->play();
    eatfruit->setVolume(100);
    eatfruit->setMedia(QUrl("qrc:/music/eatfruit.mp3"));
    star->setVolume(100);
    star->setMedia(QUrl("qrc:/music/star.mp3"));
    hitwall->setVolume(100);
    hitwall->setMedia(QUrl("qrc:/music/hitwall"));

    snake = new Snake(900,400);
    snakke = new snaket(550,650);

    connect(roundtimer,SIGNAL(timeout()),this,SLOT(startNewRound()));
    connect(timer,SIGNAL(timeout()),this,SLOT(playmusic()));

}

void gameconsole::displayMainMenu()
{
    gameScore->setVisible(false);
    gameScore->setscore(0);
    //setting the text title
    //adding the text
    Title->setPlainText("Snake Game");
    gamescene->addItem(Title);
    gamescene->addItem(credits);
    gamescene->addItem(mainButton);
    gamescene->addItem(quitButton);
    gamescene->addItem(dButton);
    gamescene->removeItem(backButton);
}

void gameconsole::start2()
{
    player = 2;
    snake = new Snake(900,350);
    snakke = new snaket(550,650);
    gamescene->removeItem(Title);
    gamescene->removeItem(mainButton);
    gamescene->removeItem(quitButton);
    gamescene->removeItem(dButton);
    gamescene->removeItem(credits);

    snake->setFlag(QGraphicsItem::ItemIsFocusable);
    snake->setFocus();
    gamescene->addItem(snake);
    snakke->setFlag(QGraphicsItem::ItemIsFocusable);
    snakke->setFocus();
    gamescene->addItem(snakke);
    walls = new wall(1,1);
    gamescene->addItem(walls);
    Bug = new bug();
    berry = new fruit("berry");
    mango = new fruit("mango");
    byul = new class star();

}



void gameconsole::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)   pause();
    if(snake){
        snake->keyPressEvent(event);}
    if (snakke){
        snakke->keyPressEvent(event);
    }
    else {
        QGraphicsView:keyPressEvent(event);
    }
}

void gameconsole::gameOver()
{
    gamescene->removeItem(snake);
    gamescene->removeItem(mango);
    gamescene->removeItem(berry);
    gamescene->removeItem(byul);
    gamescene->removeItem(Bug);
    gamescene->removeItem(snakke);
    gamescene->removeItem(walls);
    Bug->timer->stop();
    mango->timer->stop();
    berry->timer->stop();
    byul->timer->stop();



    snake->hearts->number = 3;
    snakke->hearts->number = 3;
    gameScore->setVisible(false);
    gameScore->setscore(0);
    gameScore->refreshScore();

    Title->setPlainText("GAME OVER");
    gamescene->addItem(Title);
    gamescene->addItem(backButton);
    gamescene->addItem(quitButton);
}

void gameconsole::resetround()
{
    int heartnum = snake->hearts->number;
    gamescene->removeItem(snake);
    snake = new Snake(500,200);
    snake->hearts->number = heartnum;
    snake->hearts->setpic();
    snake->setFlag(QGraphicsItem::ItemIsFocusable);
    snake->setFocus();
    gamescene->addItem(snake);
    if(player == 2){
        int heartnum2 = snakke->hearts->number;
        gamescene->removeItem(snakke);
        snakke = new snaket(500,700);
        snakke->hearts->number = heartnum2;
        snakke->hearts->setpic();
        snakke->setFlag(QGraphicsItem::ItemIsFocusable);
        snakke->setFocus();
        gamescene->addItem(snakke);
    }
}

void gameconsole::pause()
{
    if(isPause == 1){
        isPause == 0;
        snake->timer->stop();
        mango->timer->stop();
        berry->timer->stop();
        roundtimer->stop();
    }
    else{
        isPause == 1;
        snake->timer->start(snake->timer->remainingTime());
        mango->timer->start(6000);
        berry->timer->start(8000);
        roundtimer->start();
    }
}

void gameconsole::startNewRound()
{
    gamescene->removeItem(walls);
    resetround();
    round++;

    if(round == 1){
        roundtimer->start(10000);
        walls = new wall(1,1);
    }
    else if(round == 2){
        roundtimer->start(80000);
        walls = new wall(1,2);
    }
    else if(round == 3){
        roundtimer->start(90000);
        walls = new wall(1,3);
    }
    else if(round == 4){
        gameOver();
        Title->setPlainText("Congratulations!");}
        gamescene->addItem(walls);
    }


void gameconsole::start()
{
    player = 1;
    gamescene->removeItem(Title);
    gamescene->removeItem(mainButton);
    gamescene->removeItem(quitButton);
    gamescene->removeItem(dButton);
    gamescene->removeItem(credits);
    roundtimer->start(60000);
    walls = new wall(1,1);
    gamescene->addItem(walls);

    snake->setFlag(QGraphicsItem::ItemIsFocusable);
    snake->setFocus();
    gamescene->addItem(snake);
    gameScore->setVisible(true);
    berry = new fruit("berry");
    Bug = new bug();
    mango = new fruit("mango");
    byul = new class star();
}

void gameconsole::playmusic()
{
    bgmusic->setPosition(0);
}
