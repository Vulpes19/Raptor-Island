#pragma once

#include "InputObserver.hpp"
#include <algorithm>

class InputManager
{
	public:
		InputManager(void);
		~InputManager(void);
		void	addObserver(InputObserver*);
		void	eraseObserver(InputObserver*);
		void	notifyOnKeyDown(void);
	private:
		std::vector<InputObserver*> observers;
};