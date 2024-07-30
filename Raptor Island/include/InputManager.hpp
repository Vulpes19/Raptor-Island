#pragma once

#include "InputObserver.hpp"
#include "GameState.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

class InputObserver;

class InputManager
{
	public:
		InputManager(void);
		~InputManager(void);
		void	addObserver(InputObserver*);
		void	eraseObserver(InputObserver*);
		void	notifyOnKeyDown(SDL_Scancode, double, SDL_Renderer *);
		void	notifyOnMouseMove(Uint8, SDL_Renderer*);
	private:
		std::vector<InputObserver*> observers;
};