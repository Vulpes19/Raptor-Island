
#pragma once

#define SDL_MAIN_HANDLED
#define WIDTH 1280
#define HEIGHT 720

#include <iostream>
#include <SDL2/SDL.h>
#include "ErrorHandler.hpp"
#include "GameObjectFactory.hpp"

class Game
{
	public:
		Game(void);
		~Game(void);
		void	handleInput(void);
		void	update(void);
		void	render(void);
		bool	isRunning(void) const;
	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
		SDL_Event	event;
		GameObject	*player;
		GameObjectFactory factory;
		bool	running = false;
};