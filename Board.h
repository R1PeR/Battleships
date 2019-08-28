#ifndef BATTLESHIPS_BOARD_H
#define BATTLESHIPS_BOARD_H
#include <QGraphicsScene>
#include "Square.h"
#include "QObject"
namespace Battleships {
	/**
	* \brief Board class, class used to display and do calculations on boards
	*/
	class Board : public QObject{
		Q_OBJECT
	private:
		/**
		 * \brief Size of board, for internal calculations
		 */
		int size;
		/**
		 * \brief List of all the squares hold by board
		 */
		QList<Battleships::Square *> squareHolder;
	public:
		/**
		 * \brief Constructor responsible for creating new board
		 * \param size - size of board
		 * \param allowClicks - should board receive click events
		 */
		Board(int size, bool allowClicks);
		/**
		 * \brief Function repsonsible for returning size of a board, both width and height are the same
		 */
		int getSize();
		/**
		 * \brief Function responsible for displaying object on scene
		 * \param scene - pointer to scene on which object will be displayed
		 * \param x - position on x axis on scene
		 * \param y - position on y axis on scene
		 */
		void display(QGraphicsScene * scene, int x, int y);
		/**
		 * \brief Function responsible for returning Square pointer
		 * \param x - position on x axis on board
		 * \param y - position on y axis on board
		 * \return Square pointer
		 */
		Battleships::Square * getSquare(int x,int y);
		/**
		 * \brief Function responsible for returning list of all Square pointer
		 * \return QList of Square pointers
		 */
		QList<Battleships::Square*> getSquares();
		/**
		 * \brief Function responsible for checking if squares are empty
		 * \param x - position on x axis on board
		 * \param y - position on y axis on board
		 * \param size - amount of squares to check
		 * \param flip - check horizontally(false) or vertically(true)
		 * \return True if squares are empty, else False
		 */
		bool checkIfEmpty(int x, int y, int size, int flip);
		/**
		 * \brief Function responsible for generating random ships on board
		 * \param big - amount of big ships
		 * \param medium - amount of medium ships
		 * \param small - amount of small ships
		 */
		void generateRandomShips(int big, int medium, int small);
	signals:
		/**
		 * \brief Signal emited when all the ships were destroyed
		 */
		void won();
	public slots:
		/**
		 * \brief Slot to check if all the ships were destoryed
		 */
		bool checkIfWon();
		/**
		 * \brief Slot to set square(s) to certain state
		 * \param x - position on x axis on board
		 * \param y - position on y axis on board
		 * \param size - amount of squares to set
		 * \param flip - set horizontally(false) or vertically(true)
		 * \param state - state to be set
		 */
		void setSquares(int x, int y, int size, int flip, int state);
	};
}
#endif