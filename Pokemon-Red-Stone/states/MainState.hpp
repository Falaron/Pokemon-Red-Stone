#pragma once

# include "State.hpp"
# include "../headers/TileMap.hpp"

class MainState :
	public State

{
public:
	MainState(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~MainState();

	void Update(const float& dt);
	void UpdateKeybinds(const float& dt);
	void Render(sf::RenderWindow* target = NULL);

	void InitTextures();

	void EndState();

private:
	Player player;		//init player class
    TileMap* tileMap;

};