# include "MainState.hpp"



MainState::MainState(sf::RenderWindow* window)
	: State(window)
{

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

void MainState::Render(sf::RenderWindow* target)
{

}

void MainState::EndState()
{
	cout << "Main State end\n";
}
