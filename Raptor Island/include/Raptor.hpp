#pragma once

#include "GameObject.hpp"
#include "InputObserver.hpp"
#include "InputDetector.hpp"
#include "Level.hpp"

class Raptor : public GameObject
{
public:
	Raptor(std::string);
	virtual ~Raptor(void);
	void	update(double) override;
	void	addCollisionObserver(CollisionObserver*);
	void	eraseCollisionObserver(CollisionObserver*);
	void	RaptorWasted(void);
private:
	std::vector<CollisionObserver*> observers; //walls, enemies etc
};