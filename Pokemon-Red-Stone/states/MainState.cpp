#include "MainState.hpp"

MainState::MainState(sf::RenderWindow *window)
    : State(window), tileMap(nullptr)
{
    // this->tileMap = nullptr;
    //  TileMap(&"res/tileset.png", sf::Vector2u(32,32), 32, 32);
}

MainState::~MainState()
{
}


void MainState::UpdateKeybinds(const float& data)
{
	this->CheckForQuit();
}

void MainState::Update(const float& data)
{
	this->UpdateKeybinds(data);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) cout << "Key B pressed !\n";
}

void MainState::Render(sf::RenderWindow *target)
{

    if (tileMap)
    {
        std::cout << "--------test i'm here\n";
        target->draw(*tileMap);
        this->tileMap->draw(*target, sf::RenderStates::Default);
    }
}


void MainState::EndState()
{
	cout << "Main State end\n";
}
