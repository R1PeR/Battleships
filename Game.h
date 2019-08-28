#ifndef BATTLESHIPS_GAME_H
#define BATTLESHIPS_GAME_H
#include <QGraphicsView>
#include <QPushButton>
#include "Constants.h"
//#include "Ai.h"
#include "Board.h"
#include "Ship.h"
#include "GameButton.h"
#include "MouseController.h"
#include "Computer.h"
/**
* \brief Game class used to display and connect all the sub classes
*/
class Game : public QGraphicsView {
	Q_OBJECT
public:
	// constructors
	Game(QWidget* parent = NULL);
	// public attributes
	QGraphicsScene * scene;
	Battleships::MouseController * mouseController;
	Battleships::Computer * computer;
	Battleships::Board * boardLeft;
	Battleships::Board * boardRight;
	Battleships::Board * boardShips;
	Battleships::Ship * bigShip;
	Battleships::Ship * mediumShip;
	Battleships::Ship * mediumShip_2;
	Battleships::Ship * smallShip;
	Battleships::Ship * smallShip_2;
	QGraphicsTextItem * text;
	Battleships::GameButton * button;
	QPushButton * buttonStart;
	QPushButton * buttonExit;
	/**
	* \brief Fuction to display main menu
	*/
	void mainMenu();
	//void drawBackground(QPainter * painter, const QRectF & rect);
public slots:
	/**
	* \brief Slot to start playing
	*/
	void play();
	/**
	* \brief Slot to quit playing
	*/
	void quit();
	/**
	* \brief Slot to restart game
	*/
	void restartGame();
};
#endif