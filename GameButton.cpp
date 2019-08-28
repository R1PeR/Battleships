#include "GameButton.h"
#include "Constants.h"
#include <QMessageBox>
#include "Game.h"
Battleships::GameButton::GameButton( MouseController * t_mouseController, QList<Ship*> t_list, Board * t_boardLeft, Board * t_boardRight, QGraphicsTextItem * t_text)
{
	this->mouseController = t_mouseController;
	listToCheck = t_list;
	boardLeft = t_boardLeft;
	boardRight = t_boardRight;
	text = t_text;
	this->setPixmap(QPixmap(BUTTON));
	connect(boardLeft, SIGNAL(won()), this, SLOT(setWonText()));
	connect(boardRight, SIGNAL(won()), this, SLOT(setWonText()));
}

void Battleships::GameButton::display(QGraphicsScene * t_scene, int t_x, int t_y)
{
	this->setPos(t_x, t_y);
	t_scene->addItem(this);
}

void Battleships::GameButton::mousePressEvent(QGraphicsSceneMouseEvent *)
{
	if (mouseController->getState() == PLACING) {
		for (int i = 0; i < listToCheck.length(); i++)
		{
			if (listToCheck[i]->getOnBoard() == false) {
				QMessageBox messageBox;
				messageBox.critical(0, "Error", "Place all of the ships");
				messageBox.setFixedSize(500, 200);
				return;
			}
			
		}
		mouseController->setState(HITTING);
		text->setPlainText("HITTING");
		boardRight->generateRandomShips(1, 2, 2);
		for (int i = 0; i < listToCheck.length(); i++)
		{
			listToCheck[i]->setAcceptTouchEvents(false);
			listToCheck[i]->setFlag(QGraphicsItem::ItemIsMovable, false);
		}
		//this->setEnabled(false);
	}
	if (mouseController->getState() == ENDGAME) {
		//printf("restart");
		emit restart();
	}

}
void Battleships::GameButton::setWonText() {
	QList<Battleships::Square *> listLeft = boardLeft->getSquares();
	QList<Battleships::Square *> listRight = boardRight->getSquares();
	mouseController->setState(ENDGAME);
	if (sender() == boardLeft) {
		text->setPlainText("Board Left Won");
	}
	else {
		text->setPlainText("Board Right Won");
	}
}