#include "Game.h"
#include <QApplication>
#include <QGraphicsPixmapItem>
#include "Square.h"
Game::Game(QWidget *parent) {
	// set up the screen
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(720, 480);
	mainMenu();
}
void Game::mainMenu() {
	//set up a main menu scene
	scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, 720, 480);
	scene->setBackgroundBrush(QImage(BACKGROUND));
	this->setScene(scene);
	buttonStart = new QPushButton("Start", this);
	buttonStart->setGeometry(QRect(QPoint(50, 100),QSize(200, 50)));
	buttonExit = new QPushButton("Exit", this);
	buttonExit->setGeometry(QRect(QPoint(50, 175), QSize(200, 50)));
	//connect buttons to actions
	connect(buttonStart, SIGNAL(released()), this, SLOT(play()));
	connect(buttonStart, SIGNAL(released()), buttonStart, SLOT(deleteLater()));
	connect(buttonStart, SIGNAL(released()), buttonExit, SLOT(deleteLater()));
	connect(buttonExit, SIGNAL(released()), this, SLOT(quit()));
}
void Game::play()
{
	// set up the scene
	scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, 720, 480);
	this->setScene(scene);

	// add/create items
	QPixmap SIDE_TRANSFORMED = QPixmap(SHIP_SIDE).transformed(QTransform().scale(-1, 1));
	QList<const QPixmap*> BIG_SHIP = { new QPixmap(SHIP_SIDE),new QPixmap(SHIP_MIDDLE), &SIDE_TRANSFORMED };
	QList<const QPixmap*> MEDIUM_SHIP = { new QPixmap(SHIP_SIDE), &SIDE_TRANSFORMED };

	boardLeft = new Battleships::Board(10, false);
	boardLeft->display(scene, 32, 32);
	boardRight = new Battleships::Board(10, true);
	boardRight->display(scene, 32, 368);
	boardShips = new Battleships::Board(3, false);
	boardShips->display(scene, 368, 32);

	mouseController = new Battleships::MouseController(0);

	Battleships::Ship::setBoard(boardLeft);
	Battleships::Square::setMouseController(mouseController);
	computer = new Battleships::Computer(boardLeft, boardRight, 10, boardRight->getSquares());
	bigShip = new Battleships::Ship(3, mouseController);
	bigShip->display(scene, 368, 32);
	bigShip->setFlag(QGraphicsItem::ItemIsMovable);
	bigShip->setAcceptedMouseButtons(Qt::LeftButton);
	mediumShip = new Battleships::Ship(2, mouseController);
	mediumShip->display(scene, 400, 32);
	mediumShip->setFlag(QGraphicsItem::ItemIsMovable);
	mediumShip->setAcceptedMouseButtons(Qt::LeftButton);
	mediumShip_2 = new Battleships::Ship(2, mouseController);
	mediumShip_2->display(scene, 432, 32);
	mediumShip_2->setFlag(QGraphicsItem::ItemIsMovable);
	mediumShip_2->setAcceptedMouseButtons(Qt::LeftButton);
	smallShip = new Battleships::Ship(1, mouseController);
	smallShip->display(scene, 400, 96);
	smallShip->setFlag(QGraphicsItem::ItemIsMovable);
	smallShip->setAcceptedMouseButtons(Qt::LeftButton);
	smallShip_2 = new Battleships::Ship(1, mouseController);
	smallShip_2->display(scene, 432, 96);
	smallShip_2->setFlag(QGraphicsItem::ItemIsMovable);
	smallShip_2->setAcceptedMouseButtons(Qt::LeftButton);
	text = new QGraphicsTextItem();
	text->setPos(500, 393);
	text->setPlainText("PLACING");
	text->setScale(2.0);
	text->setDefaultTextColor(Qt::black);
	scene->addItem(text);
	QList<Battleships::Ship *> shipList = { bigShip,mediumShip,mediumShip_2,smallShip,smallShip_2 };
	button = new Battleships::GameButton(mouseController, shipList, boardLeft, boardRight, text);
	button->display(scene, 400, 400);

	//connect button to restart game
	connect(button, SIGNAL(restart()), this, SLOT(restartGame()));
}
void Game::quit()
{
	QApplication::quit();
}
void Game::restartGame() {
	play();
}