#include "FightMenuState.hpp"


FightMenuState::FightMenuState(sf::RenderWindow* window, std::stack<State*>* states/*, std::map<std::string, int>* supportedKeys*/)
	: State(window, states)
{
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Blue);
	winclose = new sf::RectangleShape();
	font = new sf::Font();
	image = new sf::Texture();
	bg = new sf::Sprite();


	set_values();
	InitMusic("musics/battle_theme.wav");
}

FightMenuState::~FightMenuState()
{
	delete winclose;
	delete font;
	delete image;
	delete bg;
}

void FightMenuState::set_values() {

	pos = 0;
	pressed = theselect = false;
	font->loadFromFile("font\\Roboto\\Roboto-Bold.ttf");
	image->loadFromFile("sprites\\fight_bg.png");

	bg->setTexture(*image);

	bg->setScale(1, 1);
	
	pos_mouse = { 0,0 };
	mouse_coord = { 0, 0 };
	
	options = {"Fight", "Pokemon", "Run" };
	texts.resize(3);
	coords = {
		{1700,720},
		{1700,810},
		{1700,900}
	};

	sizes = { 36,36,36 };

	for (std::size_t i{}; i < texts.size(); ++i) {
		texts[i].setFont(*font);
		texts[i].setFillColor(sf::Color::Black);
		texts[i].setString(options[i]);
		texts[i].setCharacterSize(sizes[i]);
		texts[i].setOutlineColor(sf::Color::White);
		texts[i].setPosition(coords[i]);
	}
	texts[0].setOutlineThickness(10);
	pos = 0;

	winclose->setSize(sf::Vector2f(34.5, 39));
	winclose->setPosition(50, 60);
	winclose->setFillColor(sf::Color::Transparent);

}

void FightMenuState::loop_events() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
		if (pos < texts.size()-1) {
			++pos;
			pressed = true;
			texts[pos].setOutlineThickness(10);
			texts[pos - 1].setOutlineThickness(0);
			pressed = false;
			theselect = false;

			std::this_thread::sleep_for(.1s);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
		if (pos > 0) {
			--pos;
			pressed = true;
			texts[pos].setOutlineThickness(10);
			texts[pos + 1].setOutlineThickness(0);
			pressed = false;
			theselect = false;

			std::this_thread::sleep_for(.1s);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
		Fight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
		Pokemon();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
		Run();
	}
}


void FightMenuState::UpdateKeybinds(const float& data)
{
	/* Check Quit Input */
	this->CheckForQuit();

	/* MAIN STATE TRIGGER */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		StopMusic();
		this->states->push(new MainState(this->window, this->states));
	}
}

void FightMenuState::Update(const float& data, int posT)
{
	this->UpdateKeybinds(data);
	this->loop_events();
}

void FightMenuState::Render(sf::RenderWindow* target)
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

void FightMenuState::Fight()
{
	theselect = true;
	if (pos == 0) {
		options = { "Flame", "Coupe", "Surf", "Growl" };
		texts.resize(4);
		coords = {
			{1700,720},
			{1700,810},
			{1700,900},
			{1700,990}
		};

		sizes = { 36,36,36,36 };
		for (std::size_t i{}; i < texts.size(); ++i) {
			texts[i].setFont(*font);
			texts[i].setFillColor(sf::Color::Black);
			texts[i].setString(options[i]);
			texts[i].setCharacterSize(sizes[i]);
			texts[i].setOutlineColor(sf::Color::White);
			texts[i].setPosition(coords[i]);
		}
	}
	std::cout << options[pos] << '\n';
}

void FightMenuState::Pokemon()
{
	theselect = true;
	if (pos == 1) {
		//show Pokemon
	}
}

void FightMenuState::Run()
{
	theselect = true;
	if (pos == 2) {
		//Quit Fight
	}
}


void FightMenuState::EndState()
{
	cout << "Fight Menu State end\n";
}


