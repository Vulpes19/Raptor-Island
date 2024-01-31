#pragma once

#include <SDL.h>

class InputObserver
{
	public:
		virtual void	keyDown(SDL_Scancode, double) = 0;
		virtual void	mouseMove(Uint8) = 0;
};