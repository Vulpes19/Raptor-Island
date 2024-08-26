#include "Enemy.hpp"

Enemy::Enemy(std::string textureName, Vector &spawnPosition, std::vector<WayPoint> &wayPoints) : GameObject(textureName, spawnPosition), wayPoints(wayPoints)
{
	//position.setX(spawnPosition.getX());
	//position.setY(spawnPosition.getY());
	acceleration.setX(0.0001);
	acceleration.setY(0.0001);
}

Enemy::~Enemy(void)
{}

void	Enemy::update(double deltaTime)
{
	switch (currentState)
	{
		case RAPTOR_STATE::PATROL:
			if (wayPointLocked)
			{
				Vector direction = targetWaypoint - position;
				direction.normalize();

				position += direction + acceleration * deltaTime;
				/*std::cout << "pos: ";
				std::cout << position.getX() << " " << position.getY() << std::endl;
				std::cout << "target: ";
				std::cout << targetWaypoint.getX() << " " << targetWaypoint.getY() << std::endl;
				*/if (position == targetWaypoint)
				{
					//std::cout << "<<<<<<<<<<>>>>>>>>>>>>" << std::endl;
					//std::cout << "target reached" << std::endl;
					wayPointLocked = false;
					wayPoints[targetPointIndex].status = WayPoint::Status::FREE;
					lockWayPoint();
				}
			}
			else
				lockWayPoint();
			break;
		case RAPTOR_STATE::CHASE:
			break;
	default:
		break;
	}
}

void	Enemy::lockWayPoint(void)
{
	if (!wayPoints.empty())
	{
		bool foundWayPoint = false;
		
		while (!foundWayPoint)
		{
			unsigned int randomIndex = rand() % wayPoints.size();

			if (wayPoints[randomIndex].status == WayPoint::Status::FREE)
			{
				foundWayPoint = true;
				wayPointLocked = true;
				targetWaypoint = wayPoints[randomIndex].position;
				wayPoints[randomIndex].status = WayPoint::Status::RESERVED;
				targetPointIndex = randomIndex;
			}
		}
	}
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
