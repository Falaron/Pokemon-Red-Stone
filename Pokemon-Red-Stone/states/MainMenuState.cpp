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
	InitMusic("musics/main_menu.wav");
	InitSound("sounds/select.wav");
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
	font->loadFromFile("font/rainyhearts.ttf");
	image->loadFromFile("sprites/main_menu.jpg");

	bg->setTexture(*image);

	bg->setScale(1, 1);
	options = {"PRESS TO PLAY", "QUIT"};
	texts.resize(2);
	coords = { {1920 / 2 - 220, 1080 / 2 - 50},{1920 / 2 - 50,1080 / 2 + 100} };
	sizes = { 70,50 };

	for (std::size_t i{}; i < texts.size(); ++i) {
		texts[i].setFont(*font);
		texts[i].setString(options[i]);
		texts[i].setCharacterSize(sizes[i]);
		texts[i].setOutlineColor(sf::Color::Red);
		texts[i].setPosition(coords[i]);
	}
	texts[0].setOutlineThickness(3);

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
		if (pos < 1) {
			sound.play();
			++pos;
			texts[pos].setOutlineThickness(3);
			texts[pos - 1].setOutlineThickness(0);
			theselect = false;

			std::this_thread::sleep_for(.1s);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))	//move up
	{
		if (pos > 0) {
			sound.play();
			--pos;
			texts[pos].setOutlineThickness(3);
			texts[pos + 1].setOutlineThickness(0);
			theselect = false;

			std::this_thread::sleep_for(.1s);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect)	//Enter pressed
	{
		theselect = true;
		if (pos == 1) {
			window->close();
		}
		if (pos == 0) {
			InitSound("sounds/confirm.wav");
			sound.play();
			StopMusic();
			this->states->push(new MainState(this->window, this->states));
		}
		std::cout << options[pos] << '\n';
	}
}

void MainMenuState::Update(const float& dt,int posT)
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
