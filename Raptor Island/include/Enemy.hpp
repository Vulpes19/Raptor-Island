#pragma once

#include "GameObject.hpp"
#include "InputObserver.hpp"
#include "InputDetector.hpp"
#include "Level.hpp"

class Enemy : public InputObserver, public GameObject
{
public:
	Enemy(std::string, Vector);
	virtual ~Enemy(void);
	void	handleInput(void) override {};
	void	keyDown(SDL_Scancode, double, InputManager* = nullptr, SDL_Renderer* = nullptr) override {};
	void	mouseMove(Uint8, InputManager* = nullptr, SDL_Renderer* = nullptr) override {};
	void	update(double) override;
	void	addCollisionObserver(CollisionObserver*);
	void	eraseCollisionObserver(CollisionObserver*);
private:
	std::vector<CollisionObserver*> observers; //walls

};