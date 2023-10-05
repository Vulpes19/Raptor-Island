#include "Player.hpp"

Player::Player(std::string textureName) : GameObject(textureName)
{}

Player::~Player(void)
{}

void	Player::keyDown(SDL_Scancode key) override
{
	/*
	switch (key)
	{
	case SDL_SCANCODE_W:
	case SDL_SCANCODE_S:
	case SDL_SCANCODE_A:
	case SDL_SCANCODE_D:
	}*/
}

void	Player::update(void) override
{}