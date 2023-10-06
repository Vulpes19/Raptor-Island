#pragma once

#include "InputObserver.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

class InputManager
{
	public:
		InputManager(void);
		~InputManager(void);
		void	addObserver(InputObserver*);
		void	eraseObserver(InputObserver*);
		void	notifyOnKeyDown(SDL_Scancode);
	private:
		std::vector<InputObserver*> observers;
};