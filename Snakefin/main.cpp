#include <QApplication>
#include "gameconsole.h"

gameconsole *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new gameconsole();
    game->show();
    game->displayMainMenu();

    return a.exec();
}
