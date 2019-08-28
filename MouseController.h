#ifndef BATTLESHIPS_MOUSE_CONTROLLER_H
#define BATTLESHIPS_MOUSE_CONTROLLER_H
namespace Battleships {
	/**
	* \brief MouseController class is responsible for holding state of ship carried and game progress
	*/
	class MouseController {
	private:
		/**
		* \brief Current state of mouse
		*/
		int state;
		/**
		* \brief Current ship size that is being held
		*/
		int shipSize;
		/**
		* \brief If ship is flipped
		*/
		bool flip;
	public:
		/**
		* \brief Constructor that creates new MouseController
		* \param state - start state of controller
		*/
		MouseController(int state);
		/**
		* \brief Function that returns current state of mouse controller
		* \return state of mouse controller
		*/
		int getState();
		/**
		* \brief Function that sets current state of mouse controller
		*/
		void setState(int);
		/**
		* \brief Function that returns current ship size of mouse controller
		* \return ship size of mouse controller
		*/
		int getShipSize();
		/**
		* \brief Function that sets current ship size of mouse controller
		*/
		void setShipSize(int);
		/**
		* \brief Function that returns current flip of mouse controller
		* \return flip of mouse controller
		*/
		bool getFlip();
		/**
		* \brief Function that sets current flip of mouse controller
		*/
		void setFlip(int);
	};
}

#endif