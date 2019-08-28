#ifndef BATTLESHIPS_SHIP_H
#define BATTLESHIPS_SHIP_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include "Board.h"
#include "MouseController.h"
namespace Battleships {
	/**
	* \brief Ship class used to control ship placement and mouse events on it
	*/
	class Ship : public QGraphicsPixmapItem {
	private:
		/**
		* \brief Size of ship
		*/
		int size;
		/**
		* \brief If ship is flipped
		*/
		int flip;
		/**
		* \brief Start position x of ship
		*/
		int startPosX;
		/**
		* \brief Start position y of ship
		*/
		int startPosY;
		/**
		* \brief Last position x of ship
		*/
		int lastPosX;
		/**
		* \brief Last position y of ship
		*/
		int lastPosY;
		/**
		* \brief If ship is on Board
		*/
		bool onBoard;
		/**
		* \brief Static pointer to Board on which ships will be placed
		*/
		static Battleships::Board * board;
		/**
		* \brief Static pointer to MouseContoller which will operate the ships
		*/
		static Battleships::MouseController * mouseController;
	public:
		/**
		* \brief Constructor of Ship
		* \param size - size of ship
		* \param mouseController - pointer to MouseController that will control the ship
		*/
		Ship(int size, Battleships::MouseController* mouseController = nullptr);
		/**
		 * \brief Function responsible for displaying object on scene
		 * \param scene - pointer to scene on which object will be displayed
		 * \param x - position on x axis on scene
		 * \param y - position on y axis on scene
		 */
		void display(QGraphicsScene* scene, int x, int y);
		/**
		* \brief Function called when mousePressEvent occurs
		* \param event - pointer to scene mouse event
		*/
		void mousePressEvent(QGraphicsSceneMouseEvent * event);
		/**
		* \brief Function called when mouseReleaseEvent occurs
		* \param event - pointer to scene mouse event
		*/
		void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
		/**
		* \brief Function called when mouseDoubleClickEvent occurs
		* \param event - pointer to scene mouse event
		*/
		void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);
		/**
		* \brief Function that merges images
		* \param imageList - list of images to merge
		* \return single QPixmap
		*/
		static QPixmap mergeImages(QList<const QPixmap*> imageList);
		/**
		* \brief Function that sets Board on which ship can be placed
		* \param board - pointer to Board
		*/
		static void setBoard(Battleships::Board * board);
		/**
		* \brief Function that inverts number, if 0 then 1, if 1 then 0
		* \param number - number that will be inverted(only range from 0 to 1)
		* \return inverted number
		*/
		int byteNegation(int number);
		/**
		* \brief Function that snaps Ship object position to grid of Board
		*/
		void snapToGrid();
		/**
		* \brief Function that flips Ship object
		*/
		void flipShip();
		/**
		* \brief Function sets if ships is on Board
		* \param state - state to set
		*/
		void setOnBoard(bool state);
		/**
		* \brief Function that returns if ship is on Board or not
		* \return - bool of onBoard variable
		*/
		bool getOnBoard();
	};
}

#endif