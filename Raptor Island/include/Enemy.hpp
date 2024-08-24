#pragma once

#include "GameObject.hpp"
#include "InputObserver.hpp"
#include "InputDetector.hpp"
#include "Level.hpp"

enum class RAPTOR_STATE {
	PATROL,
	CHASE
};

class Enemy : public InputObserver, public GameObject
{
public:
	Enemy(std::string, Vector&, std::vector<WayPoint>&);
	virtual ~Enemy(void);
	void	handleInput(void) override {};
	void	keyDown(SDL_Scancode, double, InputManager* = nullptr, SDL_Renderer* = nullptr) override {};
	void	mouseMove(Uint8, InputManager* = nullptr, SDL_Renderer* = nullptr) override {};
	void	update(double) override;
	void	lockWayPoint(void);
	void	addCollisionObserver(CollisionObserver*);
	void	eraseCollisionObserver(CollisionObserver*);
private:
	std::vector<CollisionObserver*> observers; //walls
	std::vector<WayPoint> wayPoints; //enemy patrol waypoints
	RAPTOR_STATE	currentState = RAPTOR_STATE::PATROL;
	bool	wayPointLocked = false;
	Vector	targetWaypoint;
};