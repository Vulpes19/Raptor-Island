#include "Player.hpp"

Player::Player(std::string textureName) : GameObject(textureName)
{
	acceleration.setX(0.1);
	acceleration.setY(0.1);
}

Player::~Player(void)
{}

void	Player::keyDown(SDL_Scancode key, double deltaTime)
{
	if (InputDetector::getInstance()->isKeyPressed(key))
	{
		if (key == SDL_SCANCODE_W)
		{
			velocity.setY(velocity.getY() + acceleration.getY());
			std::cout << "W is pressed" << std::endl;
		}
		if (key == SDL_SCANCODE_S)
		{
			velocity.setY(velocity.getY() - acceleration.getY());
			std::cout << "S is pressed" << std::endl;
		}
		if (key == SDL_SCANCODE_A)
		{
			velocity.setX(velocity.getX() - acceleration.getX());
			std::cout << "A is pressed" << std::endl;
		}
		if (key == SDL_SCANCODE_D)
		{
			velocity.setX(velocity.getX() + acceleration.getX());
			std::cout << "D is pressed" << std::endl;
		}
	}
}

void	Player::update(double deltaTime)
{
	position = position + velocity;
}