#include "Enemy.hpp"

Enemy::Enemy(std::string textureName, Vector spawnPosition) : GameObject(textureName, spawnPosition)
{
	//position.setX(spawnPosition.getX());
	//position.setY(spawnPosition.getY());
	acceleration.setX(0.1);
	acceleration.setY(0.1);
}

Enemy::~Enemy(void)
{}

void	Enemy::update(double deltaTime)
{

}

void	Enemy::addCollisionObserver(CollisionObserver* observer)
{
	observers.push_back(observer);
}

void	Enemy::eraseCollisionObserver(CollisionObserver* observer)
{
	auto it = std::find(observers.begin(), observers.end(), observer);
	observers.erase(it);
}
