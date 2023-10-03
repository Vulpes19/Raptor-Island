#pragma once

#include "GameObject.hpp"

class Player : public GameObject
{
	public:
		Player(std::string);
		virtual ~Player(void);
		void	handleInput(void) override;
		void	update(void) override;
};