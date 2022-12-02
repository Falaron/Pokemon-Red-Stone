#pragma once

#include "State.hpp"
#include "../headers/TileMap.hpp"

class MainState : public State

{
public:
    MainState(sf::RenderWindow *window, std::stack<State *> *states);
    virtual ~MainState();


    
    bool CameraCollide();

    virtual void Update(const float &dt, int posT, sf::View *view) override;
    virtual void UpdateKeybinds(const float &dt) override;
    virtual void Render(sf::RenderWindow *target = NULL) override;

    void InitTiles();
    void InitView();
    void EndState();
    void CheckFightPokemon();
    int dir;

    Vector2f getNextPositionOnMap() const;

    int tileUnderPlayer;
    float movX; // player speed X axis
    float movY; // player speed Y axis

private:

    int cameraLeftBorder;
    int cameraRightBorder;
    int cameraTopBorder;
    int cameraBottomBorder;

    int mapLeftBorder;
    int mapRightBorder;
    int mapTopBorder;
    int mapBottomBorder;

   

    View view;
    Player player; // init player class
    TileMap tileMap;
};