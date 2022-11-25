#pragma once
#include "State.hpp"
class MainMenuState :
    public State
{
private:
    void initKeybinds();

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);

    void end

};

