# include "State.hpp"
# include "../headers/TileMap.hpp"

class MainState :
	public State

{
public:
	MainState(sf::RenderWindow* window);
	virtual ~MainState();

	void Update(const float& dt, int posT);
	void UpdateKeybinds(const float& dt);
	void Render(sf::RenderWindow* target = NULL);

	void InitTextures();

	void EndState();

private:
	Player player;		//init player class
    TileMap* tileMap;

};