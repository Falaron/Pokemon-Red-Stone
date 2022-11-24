# include "../states/MainState.hpp"
# include "Player.hpp"


class Game {
public:
	Game();
	~Game();

	void Run();
	void Update();
	void Render();

	void UpdateDeltaTime();

private:
	void InitWindow(int width, int height, const char* title);
	void InitStates();


	RenderWindow* window;
	Event event;

	sf::Clock deltaClock;
	float deltaTime;

	std::stack<State*> states;
};