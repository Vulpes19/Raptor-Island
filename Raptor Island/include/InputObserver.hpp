#pragma once

#include <SDL.h>

class InputObserver
{
	public:
		virtual void	keyDown(SDL_Scancode) = 0;
		virtual void	mouseMove(void) = 0;
};