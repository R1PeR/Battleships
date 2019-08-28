#ifndef BATTLESHIPS_COMPUTER_H
#define BATTLESHIPS_COMPUTER_H
#include <QList>
#include "Board.h"
namespace Battleships {
	/** 
	* \brief Computer class responsible for ai of the game
	*/
	class Computer : public QObject{
		Q_OBJECT
		private:
			/**
			* \brief Probability list of doubles
			*/
			QList<double> probabilityArray;
			/**
			* \brief Pointer to self Board
			*/
			Board * selfBoard;
			/**
			* \brief Pointer to enemy Board
			*/
			Board * enemyBoard;
			/**
			* \brief Size of square array of probabilities
			*/
			int size;
		public:
			/**
			* \brief Constructor of ai
			* \param boardSelf - pointer to self Board
			* \param boardEnemy - pointer to enemy Board
			* \param size - amount of boards
			* \param squares - List of all the squares of enemy board
			*/
			Computer(Board * boardSelf, Board * boardEnemy, int size, QList<Square*> squares);
			/**
			* \brief Fuction TODO when upgrading ai, responsible to calculating probability on board
			* \param x - position on x axis on probability array
			* \param y - position on y axis on probability array
			*/
			void updateProbability(int x, int y);
			/**
			* \brief Fuction to return size of probablity array
			* \return size of probability array
			*/
			int getSize();
		public slots:
			/**
			* \brief Slot that updates ai logic
			*/
			void update();	
	};
}
#endif