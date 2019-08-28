#ifndef BATTLESHIPS_BUTTON_H
#define BATTLESHIPS_BUTTON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "Ship.h"

namespace Battleships {
	/**
	* \brief GameButton class used to create clickable button responsible for staring and restarting game
	*/
	class GameButton : public QObject ,public QGraphicsPixmapItem {
		Q_OBJECT
	private:
		/**
		* \brief List of Ship pointers that will be checked
		*/
		QList<Battleships::Ship*> listToCheck;
		/**
		* \brief Pointer to left Board
		*/
		Battleships::Board * boardLeft;
		/**
		* \brief Pointer to right Board
		*/
		Battleships::Board * boardRight;
		/**
		* \brief Pointer to text
		*/
		QGraphicsTextItem * text;
		/**
		* \brief Pointer to MouseController
		*/
		Battleships::MouseController * mouseController;
	public:
		/**
		* \brief Constructor that creates button
		* \param mouseController - mouse controller pointer
		* \param listShips - list of all Ships that will be placed on Board
		* \param boardLeft - pointer to left Board
		* \param boardLeft - pointer to right Board
		* \param text - pointer to Text
		*/
		GameButton(Battleships::MouseController* mouseController, QList<Battleships::Ship*> listShips, Battleships::Board * boardLeft, Battleships::Board * boardRight, QGraphicsTextItem * text);
		/**
		* \brief Function to display button on scene
		* \param x - position on x axis on scene
		* \param y - position on y axis on scene
		*/
		void display(QGraphicsScene* scene, int x, int y);
		/**
		* \brief Function called when mousePressEvent occurs
		* \param event - pointer to scene mouse event
		*/
		void mousePressEvent(QGraphicsSceneMouseEvent * event);
	signals:
		/**
		* \brief Signal emited when game is being restarted
		*/
		void restart();
	public slots:
		/**
		* \brief Slot to display who won
		*/
		void setWonText();
	};
}

#endif