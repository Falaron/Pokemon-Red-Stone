# include "../states/MainState.hpp"
# include "Player.hpp"
//# include "Entity.hpp"
# include "../states/MainMenuState.hpp"
# include "../states/FightMenuState.hpp"
# include "../headers/Entity.hpp"

class Game {
public:
	Game();
	~Game();

	void Run();
	bool isOpen(void) const;
	void Update();
	void Render();
	void InitWindow(int width, int height, const char* title);
	void UpdateDeltaTime();

private:
	void InitStates();
	Player player;
	RenderWindow* window;
	Event event;

	

	sf::Clock deltaClock;
	float deltaTime;

	std::stack<State*> states;
};