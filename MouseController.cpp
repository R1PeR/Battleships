#include "MouseController.h"
namespace Battleships {


	MouseController::MouseController(int t_state) {
		this->state = t_state;
	}
	void MouseController::setState(int t_state) {
		this->state = t_state;
	}
	int MouseController::getShipSize()
	{
		return this->shipSize;
	}
	void MouseController::setShipSize(int t_shipSize)
	{
		this->shipSize = t_shipSize;
	}
	bool MouseController::getFlip()
	{
		return this->flip;
	}
	void MouseController::setFlip(int t_flip)
	{
		this->flip = t_flip;
	}
	int MouseController::getState() {
		return this->state;
	}
}