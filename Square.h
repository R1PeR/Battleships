#ifndef BATTLESHIPS_SQUARE_H
#define BATTLESHIPS_SQUARE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include "MouseController.h"
namespace Battleships {
	/**
	* \brief Square class used to control indivitual square of board
	*/
	class Square : public QObject, public QGraphicsPixmapItem {
		Q_OBJECT
	private:
		//game logic variables
		/**
		* \brief Current type of square
		*/
		int type;
		/**
		* \brief Pointer to MouseController that controls Square
		*/
		static Battleships::MouseController * mouseController;
	public:
		/**
		* \brief Default constructor
		*/
		Square();
		/**
		* \brief Pointer to MouseController that controls Square
		* \param type - starting type
		* \param allowClick - if Square should accept mouse events
		*/
		Square(int type, bool allowClicks);
		/**
		* \brief Static function that sets mouse controller
		* \param mouseController - MouseController pointer
		*/
		static void setMouseController(Battleships::MouseController * mouseController);
		/**
		* \brief Function that checks if Square was hit
		*/
		void checkIfHit();
		/**
		* \brief Function that returns type of Square
		* \return Int of type
		*/
		int getType();
		/**
		* \brief Function that sets type of Square
		* \param type - type to set
		*/
		void setType(int type);
		/**
		* \brief Function that changes pixmap of Square
		* \param link - string url to pixmap
		*/
		void changePixmap(char link[]);
		//static void setComputer(Computer *);
		
		/**
		* \brief Function called when mousePressEvent occurs
		* \param event - pointer to scene mouse event
		*/
		void mousePressEvent(QGraphicsSceneMouseEvent *event);
		/**
		* \brief Function called when mouseReleaseEvent occurs
		* \param event - pointer to scene mouse event
		*/
		void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
		/**
		* \brief Function called when hoverEnterEvent occurs
		* \param event - pointer to scene mouse event
		*/
		void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
		/**
		* \brief Function called when hoverLeaveEvent occurs
		* \param event - pointer to scene mouse event
		*/
		void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
		//void setOnClickFunction(void *);
	signals:
		/**
		* \brief Signal that is emited on click
		*/
		void onClick();
		//void afterCheck();
	};
}
#endif