#include "MainMenuState.hpp"
# include "../headers/Game.hpp"


MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states/*, std::map<std::string, int>* supportedKeys*/)
	: State(window, states)
{
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Blue);
	winclose = new sf::RectangleShape();
	font = new sf::Font();
	image = new sf::Texture();
	bg = new sf::Sprite();


	SetValues();
}

MainMenuState::~MainMenuState()
{
	delete winclose;
	delete font;
	delete image;
	delete bg;
}

void MainMenuState::SetValues() {

	pos = 0;
	theselect = false;
	font->loadFromFile("font\\Roboto\\Roboto-Bold.ttf");
	image->loadFromFile("sprites\\uwubg.jpg");

	bg->setTexture(*image);

	bg->setScale(1, 1);
	/*
	pos_mouse = { 0,0 };
	mouse_coord = { 0, 0 };
	*/
	options = { "Pokemon : Red Stone", "Play", "Quit" };
	texts.resize(3);
	coords = { {50, 100},{50,180},{50,270} };
	sizes = { 30,42,36 };

	for (std::size_t i{}; i < texts.size(); ++i) {
		texts[i].setFont(*font);
		texts[i].setString(options[i]);
		texts[i].setCharacterSize(sizes[i]);
		texts[i].setOutlineColor(sf::Color::Magenta);
		texts[i].setPosition(coords[i]);
	}
	texts[1].setOutlineThickness(10);
	pos = 1;

	winclose->setSize(sf::Vector2f(34.5, 39));
	winclose->setPosition(50, 60);
	winclose->setFillColor(sf::Color::Transparent);

}

void MainMenuState::UpdateKeybinds(const float& dt)
{
	/* Check Quit Input */
	this->CheckForQuit();

	/* Player Movement Input */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))	//move down
	{
		if (pos < 2) {
			++pos;
			texts[pos].setOutlineThickness(10);
			texts[pos - 1].setOutlineThickness(0);
			theselect = false;

			std::this_thread::sleep_for(.1s);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))	//move up
	{
		if (pos > 1) {
			--pos;
			texts[pos].setOutlineThickness(10);
			texts[pos + 1].setOutlineThickness(0);
			theselect = false;

			std::this_thread::sleep_for(.1s);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect)	//Enter pressed
	{
		theselect = true;
		if (pos == 2) {
			window->close();
		}
		if (pos == 1) {
			this->states->push(new MainState(this->window, this->states));
		}
		std::cout << options[pos] << '\n';
	}
}

void MainMenuState::Update(const float& dt)
{
	this->UpdateKeybinds(dt);
}

void MainMenuState::Render(sf::RenderWindow* target)
{

	if (!target)	target = this->window;

	//target->draw(this->background);
	target->draw(*bg);
	for (auto t : texts) {
		target->draw(t);
	}


	/*
	if (tileMap)
	{
		std::cout << "--------test i'm here\n";
		target->draw(*tileMap);
		this->tileMap->draw(*target, sf::RenderStates::Default);
	}
	*/


}

void MainMenuState::EndState()
{
	cout << "Main Menu State end\n";
}
