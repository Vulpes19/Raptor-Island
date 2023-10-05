#include "InputDetector.hpp"

InputDetector* InputDetector::instance = nullptr;

InputDetector::InputDetector(void)
{}

InputDetector::~InputDetector(void)
{}

InputDetector* InputDetector::getInstance(void)
{
	if (instance == nullptr)
		return (new InputDetector());
	return (instance);
}

bool	InputDetector::isKeyPressed(SDL_Scancode key) const
{
	if (keyboardState[key])
		return (true);
	else
		return (false);
}