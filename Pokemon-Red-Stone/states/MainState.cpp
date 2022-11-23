# include "MainState.hpp"



MainState::MainState(sf::RenderWindow* window)
	: State(window)
{

}

MainState::~MainState()
{

}

void MainState::Update(const float& data)
{
	std::cout << "test i'm here\n";
}

void MainState::Render(sf::RenderWindow* target)
{

}

void MainState::EndState()
{

}
