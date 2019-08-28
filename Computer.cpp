#include "Computer.h"
#include "Constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
namespace Battleships {
	Computer::Computer(Board * t_boardLeft, Board * t_boardRight,int t_size, QList<Square*> t_list)
	{
		probabilityArray = {};
		selfBoard = t_boardLeft;
		enemyBoard = t_boardRight;
		this->size = t_size;
		for (int i = 0; i < t_size; i++) {
			probabilityArray.append(1.0);
		}
		for (int i = 0; i < t_list.length(); i++) {
			connect(t_list[i], SIGNAL(onClick()), this, SLOT(update()));
		}
	}
	void Computer::update()
	{
		srand(time(NULL));
		int x, y;
		
		bool found = false;
		while (found == false) {
			x = rand() % 10;
			y = rand() % 10;
			//printf("%d, %d\n", x, y);
			if (selfBoard->getSquare(x, y)->getType() != HIT) {
				selfBoard->getSquare(x, y)->checkIfHit();
				selfBoard->getSquare(x, y)->setType(HIT);
				/*if (board->getSquare(x, y)->getType() != EMPTY) {
					//updateProbability(x, y);
					board->getSquare(x, y)->setType(HIT);
				}
				else {
					//probabilityArray[this->getSize() * x + y] = 0.0;
					board->getSquare(x, y)->setType(HIT);
				}*/
				found = true;
			}
		}
		
	}
	void Computer::updateProbability(int t_x, int t_y)
	{
		//printf("Update");
		probabilityArray[this->getSize() * t_x + t_y] = 0.0;
		if (t_x - 1 > 0) {
			if (probabilityArray[this->getSize() * (t_x - 1) + t_y] != 0.0) {
				probabilityArray[this->getSize() * (t_x - 1) + t_y] += 0.25;
			}
		}
		if (t_y - 1 > 0) {
			if (probabilityArray[this->getSize() * t_x + (t_y - 1)] != 0.0) {
				probabilityArray[this->getSize() * t_x + (t_y - 1)] += 0.25;
			}
		}
		if (t_x + 1 < 10) {
			if (probabilityArray[this->getSize() * (t_x + 1) + t_y] != 0.0) {
				probabilityArray[this->getSize() * (t_x + 1) + t_y] += 0.25;
			}
		}
		if (t_y + 1 < 10) {
			if (probabilityArray[this->getSize() * t_x + (t_y + 1)] != 0.0) {
				probabilityArray[this->getSize() * t_x + (t_y + 1)] += 0.25;
			}
		}
	}

	int Computer::getSize()
	{
		return size;
	}
}
