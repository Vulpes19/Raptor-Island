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
		if (key == SDL_SCANCODE_S)
		{
			velocity.setY(velocity.getY() + acceleration.getY());
			velocity.setX(0);
			std::cout << "W is pressed" << std::endl;
		}
		if (key == SDL_SCANCODE_W)
		{
			velocity.setY(velocity.getY() - acceleration.getY());
			velocity.setX(0);
			std::cout << "S is pressed" << std::endl;
		}
		if (key == SDL_SCANCODE_A)
		{
			velocity.setX(velocity.getX() - acceleration.getX());
			velocity.setY(0);
			std::cout << "A is pressed" << std::endl;
		}
		if (key == SDL_SCANCODE_D)
		{
			velocity.setX(velocity.getX() + acceleration.getX());
			velocity.setY(0);
			std::cout << "D is pressed" << std::endl;
		}
	}
}

void	Player::update(double deltaTime)
{
	position = position + velocity;
	if (position.getX() < MIN_X)
	{
		position.setX(MIN_X);
		velocity.setX(0);
	}
	if (position.getX() + 64 > MAX_X)
	{
		position.setX(MAX_X - 64);
		velocity.setX(0);
	}
	if (position.getY() < MIN_Y)
	{
		position.setY(MIN_Y);
		velocity.setY(0);
	}
	if (position.getY() + 64 > MAX_Y)
	{
		position.setY(MAX_Y - 64);
		velocity.setY(0);
	}
}