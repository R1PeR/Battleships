#include <QApplication>
#include "Game.h"
int main(int argc, char *argv[])
{
	//create new application
	QApplication a(argc, argv);
	//create new game and show it
	Game * game = new Game();
	game->show();
	return a.exec();
}
