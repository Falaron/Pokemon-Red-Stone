#include "MainMenuState.hpp"
# include "../headers/Game.hpp"
# include "../headers/Config.hpp"


MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
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

void MainMenuState::SetValues()//will set all values at the start of the fight
{

	pos = 0;//position of the selected option in the menu
	theselect = false;
	font->loadFromFile("font/rainyhearts.ttf");
	image->loadFromFile("sprites/main_menu.jpg");//background image

	bg->setTexture(*image);
	bg->setScale(1, 1);
	//Text display Main menu
	options = {"PRESS TO PLAY", "QUIT"};//options. if you add another string for another option, don't forget to change the text.resize just below
	texts.resize(2);
	coords = { {WINDOW_WIDTH / 2 - 220, WINDOW_HEIGHT / 2 - 50},{WINDOW_WIDTH / 2 - 50,WINDOW_HEIGHT / 2 + 100} };//coordinates of each options
	sizes = { 70,50 };//Ffont size

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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))	//move down in the menu
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))	//move up in the menu
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
		if (pos == 1) {//quit 
			this->states->top()->EndState();
			this->window->close();
		}
		if (pos == 0) {//play game
			 InitSound("sounds/confirm.wav");
			 sound.play();
			 StopMusic();
			this->states->push(new MainState(this->window, this->states));//Change to main state (game)
		}
		//std::cout << options[pos] << '\n';
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
}

void MainMenuState::EndState()
{
	cout << "Main Menu State end\n";
}
