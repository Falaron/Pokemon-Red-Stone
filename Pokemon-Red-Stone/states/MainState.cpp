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
	/* Check Quit Input */
	this->CheckForQuit();

	/* Player Movement Input */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) cout << "I move Left\n";	// this->player.move(deltaTime, move Value Left)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) cout << "I move Right\n";	// this->player.move(move Value Right)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) cout << "I move Up\n";		// this->player.move(move Value Up)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) cout << "I move Down\n";	// this->player.move(move Value Down)
}

void MainState::Update(const float& data)
{
	this->UpdateKeybinds(data);
}

void MainState::Render(sf::RenderWindow* target)
{

}

void MainState::EndState()
{
	cout << "Main State end\n";
}
