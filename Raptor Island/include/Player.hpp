#pragma once

#include "GameObject.hpp"
#include "InputObserver.hpp"
#include "InputDetector.hpp"
#include "Level.hpp"

class Player : public InputObserver, public GameObject
{
	public:
		Player(std::string);
		virtual ~Player(void);
		void	handleInput(void) override {};
		void	keyDown(SDL_Scancode, double) override;
		void	mouseMove(void) override {};
		void	update(double) override;
		void	addCollisionObserver(CollisionObserver*);
		void	eraseCollisionObserver(CollisionObserver*);
	private:
		std::vector<CollisionObserver*> observers; //walls, enemies etc
};