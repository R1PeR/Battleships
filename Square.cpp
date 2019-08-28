#include "Square.h"
#include "Constants.h"
Battleships::MouseController *Battleships::Square::mouseController = nullptr;
Battleships::Square::Square()
{
	this->type = 0;
	this->setPixmap(QPixmap(WATER));
	this->setAcceptHoverEvents(true);
}
Battleships::Square::Square(int t_type, bool t_allowClicks)
{
	this->type = t_type;
	this->setPixmap(QPixmap(WATER));
	this->setAcceptHoverEvents(t_allowClicks);
	if (!t_allowClicks) {
		this->setAcceptedMouseButtons(NULL);
	}
}
void Battleships::Square::setType(int t_type) {
	this->type = t_type;
}
void Battleships::Square::changePixmap(char t_texture[])
{
	this->setPixmap(QPixmap(t_texture));
}
/*void Battleships::Square::setComputer(Computer * t_computer)
{
	Battleships::Square::computer = t_computer;
}*/
void Battleships::Square::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
	
	if (this->type != HIT && this->mouseController->getState() == HITTING) {
		checkIfHit();
	}
}

void Battleships::Square::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{

}

void Battleships::Square::hoverEnterEvent(QGraphicsSceneHoverEvent * event)
{
	if (this->type == EMPTY || this->type == BATTLESHIP_SMALL || this->type == BATTLESHIP_MEDIUM || this->type == BATTLESHIP_BIG) {
		this->changePixmap(WATER_HOVER);
	}
}

void Battleships::Square::hoverLeaveEvent(QGraphicsSceneHoverEvent * event)
{
	if (this->type == EMPTY || this->type == BATTLESHIP_SMALL || this->type == BATTLESHIP_MEDIUM || this->type == BATTLESHIP_BIG) {
		this->changePixmap(WATER);
	}
}

int Battleships::Square::getType() {
	return this->type;
}

void Battleships::Square::setMouseController(MouseController * t_mouseController) {
	Battleships::Square::mouseController = t_mouseController;
}
void Battleships::Square::checkIfHit() {
	emit onClick();
	switch (this->type) {
	case EMPTY:
		this->changePixmap(WATER_HIT);
		this->type = HIT;
		break;
	case BATTLESHIP_SMALL:
		this->changePixmap(SHIP_HIT);
		this->type = HIT;
		this->setZValue(20);
		break;
	case BATTLESHIP_MEDIUM:
		this->changePixmap(SHIP_HIT);
		this->type = HIT;
		this->setZValue(20);
		break;
	case BATTLESHIP_BIG:
		this->changePixmap(SHIP_HIT);
		this->type = HIT;
		this->setZValue(20);
		break;
	}
	emit afterCheck();
}