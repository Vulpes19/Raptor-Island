#include "GameState.hpp"
#include "InputObserver.hpp"
#include "InputDetector.hpp"
#include "InputManager.hpp"
#include "StatesManager.hpp"

class PauseMenu : public GameState, public InputObserver
{
public:
	PauseMenu(void);
	~PauseMenu(void);
	void handleInput(void) override;
	void keyDown(SDL_Scancode, double, InputManager*, SDL_Renderer*) override;
	void mouseMove(Uint8, InputManager*, SDL_Renderer*) override;
	void update(double = 0) override;
	void render(SDL_Renderer*) override;
private:
	std::map<std::string, BUTTON_STATE> buttonsState;
};