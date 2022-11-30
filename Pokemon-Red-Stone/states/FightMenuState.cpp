#pragma once
#include <stdlib.h>
#include "FightMenuState.hpp"
#include "../headers/Game.hpp"
#include "../headers/Pikachu.hpp"
#include "../headers/EnnemiPoke.hpp"
#include "../headers/Config.hpp"
#include "../headers/Entity.hpp"

EnnemiPoke ennemipoke = EnnemiPoke(ennemipoke.imageTiplouf);

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
	//tiplouf = new sf::Sprite();
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
	//imageTiplouf.loadFromFile("sprites\\tiplouf.png");
	//imagee.loadFromFile(TIPLOUF_TEXTURE_PATH);

	bg->setTexture(*image);
	bg->setScale(1, 1);

	pikachu->setTexture(imagePikachu);
	pikachu->setPosition(sf::Vector2f(350, 450)); // position absolue



	
	SetPoke();
	Menu();
	texts[0].setOutlineThickness(10);
	pos = 0;

	winclose->setSize(sf::Vector2f(34.5, 39));
	winclose->setPosition(50, 60);
	winclose->setFillColor(sf::Color::Transparent);
}

void FightMenuState::SetPoke() {
	ennemipoke.tiplouf();
	int ennmipp = ennemipoke.pp;
	this->EnnemiMaxHp = ennemipoke.life;
	this->EnnemiCurrentHp = this->EnnemiMaxHp;
	cout << "ennemi hp :" << EnnemiMaxHp << "\n";

}

void FightMenuState::DmgEnnemiHp(int skillDmg) {
	this->EnnemiCurrentHp -= skillDmg;
}

void FightMenuState::EnnemiHp() {
	int hp = this->EnnemiCurrentHp;
	EnnemiHpText.setFont(*font);
	EnnemiHpText.setFillColor(sf::Color::Black);
	EnnemiHpText.setString(std::to_string(hp));
	EnnemiHpText.setPosition(800, 200);
}

void FightMenuState::textAfteratk() {
	cout << "text after atk\n";
	TextAfterAtk.setFont(*font);
	TextAfterAtk.setFillColor(sf::Color::Black);
	TextAfterAtk.setString("Ennemie pokemon took damage !");
	TextAfterAtk.setPosition(200, 100);
	sleep(milliseconds(1500));
	TextAfterAtk.setString("");
	Menu();
}

void FightMenuState::textReturnToMenu() {
	cout << "text return\n";
	TextReturnToMenu.setFont(*font);
	TextReturnToMenu.setFillColor(sf::Color::Black);
	TextReturnToMenu.setString("Return");
	TextReturnToMenu.setPosition(200, 100);
	sleep(milliseconds(1000));
	TextReturnToMenu.setString("");
	Menu();
}

void FightMenuState::EnnemiAtk(){

}

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
		else
		{
			pressed = true;
			texts[pos].setOutlineThickness(4);
			texts[pos - 1].setOutlineThickness(0);
			pos = texts.size() - 1;
			pressed = false;
			theselect = false;
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
		else
		{
			
			pressed = true;
			texts[pos].setOutlineThickness(4);
			texts[pos + 1].setOutlineThickness(0);
			pos = 0;
			pressed = false;
			theselect = false;

		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
		sleep(milliseconds(200));
		if (pos == 0 ) {
			if (!fightmenu && !pokemonmenu) {
				Fight();
				cout << "faitooo\n";
			}
			if (fightmenu && sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				pos = 0;
				textReturnToMenu();
			}
		}
		else if (pos == 1) {
			if (!pokemonmenu  && !fightmenu) {
				Pokemon();
				cout << "I PLAY POKEMON GO EVERYDAY\n";
			}
			if (fightmenu)
			{
				
				DmgEnnemiHp(20);
				cout << options[1] << " !!!!!!!!!!!!!!!!!!!\n";
				pos = 0;
				textAfteratk();
				EnnemiAtk();
				
			}
		}
		else if (pos == 2)
		{
			if (!pokemonmenu && !fightmenu) {
				Run();
				cout << "ALED\n";
			}
			if (fightmenu)
			{

				DmgEnnemiHp(25);
				cout << options[2] << " !!!!!!!!!!!!!!!!!!!\n";
				pos = 0;
				textAfteratk();
			}
		}
		else if (pos == 3) {
			if (fightmenu)
			{

				DmgEnnemiHp(12);
				cout << options[3] << " !!!!!!!!!!!!!!!!!!!\n";
				pos = 0;
				textAfteratk();
			}
		}
		else if (pos == 4) {
			if (fightmenu)
			{

				DmgEnnemiHp(15);
				cout << options[4] << " !!!!!!!!!!!!!!!!!!!\n";
				pos = 0;
				textAfteratk();
			}
		}
	}

}

void FightMenuState::UpdateKeybinds(const float& data)
{
	/* Check Quit Input */
	this->CheckForQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		StopMusic();
	}
	/* MAIN STATE TRIGGER */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		StopMusic();
		this->states->push(new MainState(this->window, this->states));
	}
}

void FightMenuState::Update(const float& data, int posT)
{
	if (EnnemiCurrentHp <= 0)
	{
		cout << "ennemi vaincu !\n";
		this->states->push(new MainState(this->window, this->states));
	}
	this->UpdateKeybinds(data);
	this->EnnemiHp();
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
	options = {  "Return", "Flame", "Coupe", "Surf", "Growl"};
	texts.resize(5);
	coords = {
		{1700,600},
		{1700,720},
		{1700,810},
		{1700,900},
		{1700,990}
		
	};

	sizes = { 36,36,36,36,36 };
	for (std::size_t i{}; i < texts.size(); ++i) {
		texts[i].setFont(*font);
		texts[i].setFillColor(sf::Color::Black);
		texts[i].setString(options[i]);
		texts[i].setCharacterSize(sizes[i]);
		texts[i].setOutlineColor(sf::Color::White);
		texts[i].setPosition(coords[i]);
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
		{1700,600}
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

void FightMenuState::Run()
{
	theselect = true;
	//rand() % 50;
	this->states->push(new MainState(this->window, this->states));
	
}

void FightMenuState::Render(sf::RenderWindow* target)
{
	if (!target)	target = this->window;

	target->draw(*bg);
	target->draw(*pikachu);
	target->draw(*ennemipoke.TiploufSprite);
	target->draw(EnnemiHpText);
	target->draw(TextAfterAtk);
	target->draw(TextReturnToMenu);

	for (auto t : texts) {
		target->draw(t);
	}

}

void FightMenuState::EndState()
{
	cout << "Fight State end\n";
}


