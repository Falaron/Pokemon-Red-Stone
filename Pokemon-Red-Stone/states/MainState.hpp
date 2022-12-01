#pragma once

# include "State.hpp"
# include "../headers/TileMap.hpp"

class MainState :
	public State

{
public:
	MainState(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~MainState();

	void Update(const float& dt, int posT);
	void UpdateKeybinds(const float& dt);
	void Render(sf::RenderWindow* target = NULL);

    void InitTiles();

	void EndState();
	int dir;

    Vector2f getNextPositionOnMap() const;

	int tileUnderPlayer;
	float movX;//player speed X axis
	float movY;//player speed Y axis

private:
	Player player;		//init player class
    TileMap tileMap;


};