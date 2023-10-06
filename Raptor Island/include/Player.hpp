#pragma once

#include "GameObject.hpp"
#include "InputObserver.hpp"
#include "InputDetector.hpp"

class Player : public InputObserver, public GameObject
{
	public:
		Player(std::string);
		virtual ~Player(void);
		void	handleInput(void) override {};
		void	keyDown(SDL_Scancode) override;
		void	mouseMove(void) override {};
		void	update(void) override;
};