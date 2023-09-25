#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game game;
    ViewGUI view(&game);
    MainWindow w(&game,&view);
    w.show();
    return a.exec();
}


