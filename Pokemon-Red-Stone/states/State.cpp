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
	music.setPitch(1.5);
	music.setVolume(50);
	music.setLoop(true);
	music.play();
}

void State::InitSound(const char* path)
{
	buffer.loadFromFile(path);
	sound.setBuffer(buffer);
}

void State::StopMusic()
{
	if (music.getStatus() == sf::Music::Status::Playing) music.stop();
}
