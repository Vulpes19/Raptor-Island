#include "Player.hpp"

Player::Player(std::string textureName, Vector position) : GameObject(textureName, position)
{
	acceleration.setX(0.1);
	acceleration.setY(0.1);
}

Player::~Player(void)
{}

void	Player::keyDown(SDL_Scancode key, double deltaTime, InputManager*, SDL_Renderer*)
{
	const double accelerationLimit = 0.5;
	if (InputDetector::getInstance()->isKeyPressed(key))
	{
		if (key == SDL_SCANCODE_S)
		{
			if (velocity.getY() + acceleration.getY() <= accelerationLimit)
				velocity.setY(velocity.getY() + acceleration.getY());
			velocity.setX(0);
			std::cout << "W is pressed " << velocity.getY() << std::endl;
		}
		if (key == SDL_SCANCODE_W)
		{
			if (velocity.getY() - acceleration.getY() >= -accelerationLimit)
				velocity.setY(velocity.getY() - acceleration.getY());
			velocity.setX(0);
			std::cout << "S is pressed " << velocity.getY() << std::endl;
		}
		if (key == SDL_SCANCODE_A)
		{
			if (velocity.getX() - acceleration.getX() >= -accelerationLimit)
				velocity.setX(velocity.getX() - acceleration.getX());
			velocity.setY(0);
			std::cout << "A is pressed " << velocity.getY() << std::endl;
		}
		if (key == SDL_SCANCODE_D)
		{
			if (velocity.getX() + acceleration.getX() <= accelerationLimit)
				velocity.setX(velocity.getX() + acceleration.getX());
			velocity.setY(0);
			std::cout << "D is pressed " << velocity.getY() << std::endl;
		}
	}
}

void	Player::update(double deltaTime)
{
	for (auto observer : observers)
	{
		enum COLLISION type = observer->checkCollision(position + velocity);
		switch (type) {
			case COLLISION::WALL:
				velocity.setX(0);
				velocity.setY(0);
				break;
			case COLLISION::ENEMY:
				playerWasted();
				return;
			default:
				position = position + velocity;
				break;
		}
	}
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

void	Player::addCollisionObserver(CollisionObserver* observer)
{
	observers.push_back(observer);
}

void	Player::eraseCollisionObserver(CollisionObserver* observer)
{
	auto it = std::find(observers.begin(), observers.end(), observer);
	observers.erase(it);
}

void	Player::playerWasted()
{

}