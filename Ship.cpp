#include "Ship.h"
#include "Constants.h"
#include <QPainter>

Battleships::Board *Battleships::Ship::board = nullptr;

Battleships::MouseController *Battleships::Ship::mouseController = nullptr;

Battleships::Ship::Ship(int t_size, MouseController * t_mouseController)
{
	flip = 0;
	size = t_size;
	onBoard = false;
	lastPosX = -1;
	lastPosY = -1;
	this->mouseController = t_mouseController;
	if (t_size > 1) {
		QList<const QPixmap*> pixmapList;
		pixmapList.append(new QPixmap(SHIP_SIDE));
		for (int i = 0; i < t_size - 2; i++) {
			pixmapList.append(new QPixmap(SHIP_MIDDLE));
		}
		QPixmap * tempPixmap = new QPixmap(SHIP_SIDE);
		QPixmap tempTransformed = tempPixmap->transformed(QTransform().scale(-1, 1));
		pixmapList.append(&tempTransformed);
		this->setPixmap(mergeImages(pixmapList));
	}
	else {
		this->setPixmap(QPixmap(SHIP_ONE));
	}
}

void Battleships::Ship::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
	if (mouseController->getState() == PLACING) {
		double xx = x();
		double yy = y();
		if (onBoard) {
			//printf("%d, %d\n", int((xx - 32) / 32), int((yy - 32) / 32));
			board->setSquares(int((xx - 32) / 32), int((yy - 32) / 32), this->size, this->flip, 0);
			this->onBoard = false;
			this->lastPosY = xx;
			this->lastPosX = yy;
		}
		QGraphicsPixmapItem::mousePressEvent(event);
	}
}

void Battleships::Ship::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
	if (mouseController->getState() == PLACING) {
		snapToGrid();
		QGraphicsPixmapItem::mouseReleaseEvent(event);
	}
}

void Battleships::Ship::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event)
{
	if (mouseController->getState() == PLACING) {
		double xx = x();
		double yy = y();
		if (this->onBoard) {
			board->setSquares(int((xx - 32) / 32), int((yy - 32) / 32), this->size, this->flip, 0);
			this->onBoard = false;
			if (board->checkIfEmpty((xx - 32) / 32, (yy - 32) / 32, this->size, this->byteNegation(flip))) {
				flipShip();
			}
		}
	}
}

QPixmap Battleships::Ship::mergeImages(QList<const QPixmap*> t_images)
{
	const int S_iconSize = 32;     //The pictures are all quadratic.
	QImage resultImage(S_iconSize*t_images.size(), S_iconSize, QImage::Format_ARGB32_Premultiplied);
	QPainter painter;

	painter.begin(&resultImage);
	for (int i = 0; i < t_images.size(); ++i)
	{
		painter.drawImage(S_iconSize*i, 0, t_images.at(i)->toImage(), 0, 0, S_iconSize, S_iconSize, Qt::AutoColor);
	}
	painter.end();
	return QPixmap::fromImage(resultImage);
}

void Battleships::Ship::setBoard(Board * t_board)
{
	Battleships::Ship::board = t_board;
}

void Battleships::Ship::display(QGraphicsScene * t_scene, int t_x, int t_y)
{
	this->startPosY = t_x;
	this->startPosX = t_y;
	this->setPos(t_y, t_x);
	t_scene->addItem(this);
}

int Battleships::Ship::byteNegation(int n_i) {
	if (n_i == 1) {
		return 0;
	}
	else {
		return 1;
	}
}

void Battleships::Ship::snapToGrid() {
	double xx = x();
	double yy = y();
	if (xx < 32.0 || yy < 32.0 || xx > (320.0 - ((size - 1) * 32 * (byteNegation(flip)))) || yy > (320.0 - ((size - 1) * 32 * (flip))))
	{
		setPos(this->startPosX, this->startPosY);
		this->flip = 0;
		this->setRotation(0);
		this->setOffset(0, 0);
	}
	else {
		xx = 32.0*round(xx / 32.);
		yy = 32.0*round(yy / 32.);
		if (xx > (320 - ((size - 1) * 32 * (byteNegation(flip))))) {
			xx = 320 - ((size - 1) * 32 * (byteNegation(flip)));
		}
		else if (xx < 32) {
			xx = 32;
		}
		if (yy > (320 - ((size - 1) * 32 * (flip)))) {
			yy = 320 - ((size - 1) * 32 * (flip));
		}
		else if (yy < 32) {
			yy = 32;
		}
		//printf("%d ,%d\n", (int)((xx - 32) / 32), (int)((yy - 32) / 32));
		if (board->checkIfEmpty(int((xx - 32) / 32), int((yy - 32) / 32), this->size, this->flip)) {
			setPos(xx, yy);
			board->setSquares(int((xx - 32) / 32), int((yy - 32) / 32), this->size, this->flip, this->size);
			onBoard = true;
		}
		else if (lastPosX != -1 && lastPosY != -1) {
			setPos(lastPosY, lastPosX);
			board->setSquares((lastPosY - 32) / 32, (lastPosX - 32) / 32, this->size, this->flip, this->size);
			onBoard = true;
		}
		else {
			setPos(startPosX, startPosY);
		}
	}

}

void Battleships::Ship::setOnBoard(bool t_onBoard)
{
	this->onBoard = t_onBoard;
}

bool Battleships::Ship::getOnBoard()
{
	return this->onBoard;
}

void Battleships::Ship::flipShip() {
	if (this->flip == 0) {
		this->flip = 1;
		this->setRotation(90);
		this->setOffset(0, -32);
	}
	else {
		this->flip = 0;
		this->setRotation(0);
		this->setOffset(0, 0);
	}
}