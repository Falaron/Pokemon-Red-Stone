#pragma once

#include "FightMenuState.hpp"
#include "../headers/Game.hpp"
#include "../headers/Pikachu.hpp"
#include "../headers/EnnemiPoke.hpp"
#include "../headers/Config.hpp"
#include "../headers/Entity.hpp"


FightMenuState::FightMenuState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Blue);
	winclose = new sf::RectangleShape();
	font = new sf::Font();
	image = new sf::Texture();
	bg = new sf::Sprite();
	pikachu = new sf::Sprite();
	tiplouf = new sf::Sprite();
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
	imagePikachu.loadFromFile(PIKACHU_TEXTURE_PATH);
	imageTiplouf.loadFromFile("sprites\\tiplouf.png");
	//imagee.loadFromFile(TIPLOUF_TEXTURE_PATH);

	bg->setTexture(*image);
	bg->setScale(1, 1);

	pikachu->setTexture(imagePikachu);
	pikachu->setPosition(sf::Vector2f(350, 450)); // position absolue

	tiplouf->setTexture(imageTiplouf);
	tiplouf->setScale(0.25, 0.25);
	tiplouf->setPosition(sf::Vector2f(850, 450));

	
	//SetPoke();
	Menu();
	texts[0].setOutlineThickness(10);
	pos = 0;

	winclose->setSize(sf::Vector2f(34.5, 39));
	winclose->setPosition(50, 60);
	winclose->setFillColor(sf::Color::Transparent);
}

//void FightMenuState::SetPoke() {
//	EnnemiPoke ennemipoke = EnnemiPoke(ennemipokeslejftexture);
//	ennemipoke.tiplouf();
//	//int ennmipp = ennemipoke.pp;
//	this->maxHp = ennemipoke.life;
//	this->currentHp = this->maxHp;
//	cout << "ennemi hp :" << maxHp << "\n";
//}

void FightMenuState::loop_events() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
		if (pos < texts.size()-1) {
			++pos;
			pressed = true;
			texts[pos].setOutlineThickness(4);
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
			texts[pos].setOutlineThickness(4);
			texts[pos + 1].setOutlineThickness(0);
			pressed = false;
			theselect = false;

			std::this_thread::sleep_for(.1s);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
		if (pos == 0) {
			if (!fightmenu && !pokemonmenu ) {
				Fight();
			}
		}
		else if (pos == 1) {
			if (!pokemonmenu  && !fightmenu) {
				Pokemon();
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && !theselect) {
		
		Menu();
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

void FightMenuState::Menu() {

	menu = true;
	pokemonmenu = fightmenu = false;
	options = { "Fight", "Pokemon", "Run" };
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


}

void FightMenuState::Fight()
{
	fightmenu = menu = true;
	pokemonmenu = false;
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



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
		if (pos == 0) {

			// Entity.life -= 10;
			Menu();
		}
		else if (pos == 1) {
			
			// Entity.life -= 5
			Menu();
		}
	}
}

void FightMenuState::Pokemon()
{
	pokemonmenu = menu= true;
	fightmenu = false;
	
	options = { "Tiplouf", "Salameche", "Bulbizarre", "Magnezone" };
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
		if (pos == 0) {
			if (!fightmenu) {
				
			}
		}
		else if (pos == 1) {
			if (!pokemonmenu) {
				
			}
		}
	}

}

void FightMenuState::Run()
{
	theselect = true;
	if (pos == 2) {
		EndState();
	}
}

void FightMenuState::Render(sf::RenderWindow* target)
{
	if (!target)	target = this->window;

	target->draw(*bg);
	target->draw(*pikachu);
	target->draw(*tiplouf);

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

void FightMenuState::EndState()
{
	cout << "Fight State end\n";
}


