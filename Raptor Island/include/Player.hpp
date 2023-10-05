#pragma once

#include "GameObject.hpp"
#include "InputObserver.hpp"
#include "InputDetector.hpp"

class Player : public GameObject, public InputObserver
{
	public:
		Player(std::string);
		virtual ~Player(void);
		void	handleInput(void) override;
		void	keyDown(SDL_Scancode) override;
		void	update(void) override;
};