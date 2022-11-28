# include "State.hpp"

State::State(sf::RenderWindow* window, std::stack<State*>* states)
{
	this->window = window;
	this->states = states;
	this->quit = false;
}

State::~State()
{

}

void State::CheckForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) this->quit = true;
}

const bool& State::GetQuit() const
{
	return this->quit;
}
