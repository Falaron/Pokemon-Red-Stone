# include "../states/MainState.hpp"
# include "Player.hpp"


class Game {
public:
	Game();
	~Game();

	void Run();
	bool isOpen(void) const;
	void Update();
	void Render();
	void clear();
	void display();
	void drawEntity(const Entity&);
	void InitWindow(int width, int height, const char* title);

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