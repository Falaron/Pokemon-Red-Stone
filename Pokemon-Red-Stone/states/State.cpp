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

void State::InitMusic(const char* path)
{
	if (!music.openFromFile(path));
	music.setLoop(true);
	music.play();
}

void State::InitSound(const char* songPath)
{
	buffer.loadFromFile(songPath);
	sound.setBuffer(buffer);
}
