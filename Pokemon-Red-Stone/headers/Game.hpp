# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>
# include <SFML/System.hpp>
# include <SFML/Audio.hpp>
# include <iostream>
using namespace std;
using namespace sf;

# include "../headers/Player.hpp"
//# include "../headers/TileMap.hpp"


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

private:
	

	RenderWindow* window;
	Event event;
};