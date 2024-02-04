#pragma once

#include <SDL.h>
#include "InputManager.hpp"

class InputObserver
{
	public:
		virtual void	keyDown(SDL_Scancode, double, InputManager *, SDL_Renderer *) = 0;
		virtual void	mouseMove(Uint8, InputManager*, SDL_Renderer*) = 0;
};