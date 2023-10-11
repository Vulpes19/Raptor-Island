
#pragma once

#define SDL_MAIN_HANDLED
#define WIDTH 1280
#define HEIGHT 720

#include <iostream>
#include <SDL2/SDL.h>
#include <chrono>
#include "ErrorHandler.hpp"
#include "GameObjectFactory.hpp"
#include "InputManager.hpp"

class Game
{
	public:
		using Clock = std::chrono::high_resolution_clock;
		using Time = std::chrono::time_point<Clock>;
		Game(void);
		~Game(void);
		void	handleInput(void);
		void	update(void);
		void	render(void);
		bool	isRunning(void) const;
		void	updateDeltaTime(void);
	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
		SDL_Event	event;
		GameObject	*player;
		GameObjectFactory factory;
		InputManager* input;
		Time	prevTime;
		Time	currTime;
		double			deltaTime;
		bool	running = false;
};