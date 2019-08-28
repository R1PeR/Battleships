#include "Board.h"
#include <qmath.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Constants.h"
namespace Battleships {
	Board::Board(int t_size, bool t_allowClicks) {
		squareHolder = {};
		for (int i = 0; i < (t_size*t_size); i++) {
			this->squareHolder.append(new Square(0, t_allowClicks));
			connect(this->squareHolder[i], SIGNAL(afterCheck()), this, SLOT(checkIfWon()));
		}
		this->size = t_size;
	}
	Square * Battleships::Board::getSquare(int t_x, int t_y) {
		return this->squareHolder[this->getSize() * t_x + t_y];
	}
	QList<Battleships::Square*> Board::getSquares()
	{
		return this->squareHolder;
	}
	int Board::getSize() {
		return size;
	}

	void Board::display(QGraphicsScene * t_scene, int t_x, int t_y)
	{
		Square * t_square = nullptr;
		for (int y = 0; y < getSize(); y++) {
			for (int x = 0; x < getSize(); x++) {
				t_square = getSquare(y, x);
				t_square->setPos(t_y + (32 * y), t_x + (32 * x));
				t_scene->addItem(t_square);
			}
		}
	}

	bool Board::checkIfEmpty(int t_x, int t_y, int t_size, int t_flip) {

		int checker = 0;
		for (int i = 0; i < t_size; i++) {
			if (t_flip == 1) {
				checker += abs(getSquare(t_x, t_y + i)->getType());
			}
			else {
				checker += abs(getSquare(t_x + i, t_y)->getType());
			}
		}
		return (checker == 0 ? true : false);
	}

	void Board::setSquares(int t_x, int t_y, int t_size, int t_flip, int t_state)
	{
		for (int i = 0; i < t_size; i++) {
			if (t_flip == 1) {
				getSquare(t_x, t_y + i)->setType(t_state);
			}
			else {
				getSquare(t_x + i, t_y)->setType(t_state);
			}
		}
		/*for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				printf("%d", (this->getSquare(y, x)->getType()));
			}
			printf("\n");
		}
		printf("\n");*/
	}

	void Board::generateRandomShips(int t_big, int t_medium, int t_small)
	{
		srand(time(NULL));
		int i = 0;
		int x, y, size, flip;
		while (i != t_big) {
			x = rand() % 10; //0-9
			y = rand() % 10; //0-9
			flip = rand() % 2; // 0-1
			if ((flip == 0 && x < 8) || (flip == 1 && y < 8)) {
				if (checkIfEmpty(x, y, 3, flip)) {
					setSquares(x, y, 3, flip, 3);
					i++;
				}
			}
		}
		i = 0;
		while (i != t_medium) {
			x = rand() % 10; //0-9
			y = rand() % 10; //0-9
			flip = rand() % 2; // 0-1
			if ((flip == 0 && x < 9) || (flip == 1 && y < 9)) {
				if (checkIfEmpty(x, y, 2, flip)) {
					setSquares(x, y, 2, flip, 2);
					i++;
				}
			}
		}
		i = 0;
		while (i != t_small) {
			x = rand() % 10; //0-9
			y = rand() % 10; //0-9
			flip = rand() % 2; // 0-1
			if (checkIfEmpty(x, y, 1, flip)) {
				setSquares(x, y, 1, flip, 1);
				i++;
			}
		}
	}

	bool Board::checkIfWon() {
		//printf("checking");
		for (int i = 0; i < (size*size); i++) {
			if (squareHolder[i]->getType() == BATTLESHIP_BIG || squareHolder[i]->getType() == BATTLESHIP_MEDIUM || squareHolder[i]->getType() == BATTLESHIP_SMALL) {
				return false;
			}
		}
		emit won();
		return true;
	}
}
