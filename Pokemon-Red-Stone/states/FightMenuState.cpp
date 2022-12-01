#pragma once
#include <stdlib.h>
#include "FightMenuState.hpp"
#include "MainState.hpp"
#include "../headers/Game.hpp"
#include "../headers/Pikachu.hpp"
#include "../headers/EnnemiPoke.hpp"
#include "../headers/Config.hpp"
#include "../headers/Entity.hpp"

using namespace std;

EnnemiPoke ennemipoke = EnnemiPoke(ennemipoke.imagePoke);//create entity(pokemon). this one will be ennemi pokemon
Pikachu myPikachu = Pikachu(myPikachu.imagePikachu);//create entity(pokemon). this one will be our pokemon

FightMenuState::FightMenuState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Blue);
	winclose = new sf::RectangleShape();
	font = new sf::Font();
	image = new sf::Texture();
	bg = new sf::Sprite();
	//pikachu = new sf::Sprite();
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

	bg->setTexture(*image);
	bg->setScale(1, 1);

	SetPoke();
	Menu();
	texts[0].setOutlineThickness(10);
	pos = 0;

	this->EnnemiHpBox.setSize(sf::Vector2f(160.f, 60.f));
	this->EnnemiHpBox.setFillColor(sf::Color(100, 100, 100));
	this->EnnemiHpBox.setPosition(1670, 200);

	this->EnnemiHpBarOutline.setSize(sf::Vector2f(120.f, 5.f));
	this->EnnemiHpBarOutline.setFillColor(sf::Color::Transparent);
	this->EnnemiHpBarOutline.setOutlineColor(sf::Color::Black);
	this->EnnemiHpBarOutline.setOutlineThickness(1);
	this->EnnemiHpBarOutline.setPosition(1680, 245);

	this->OurHpBox.setSize(sf::Vector2f(160.f, 60.f));
	this->OurHpBox.setFillColor(sf::Color(100, 100, 100));
	this->OurHpBox.setPosition(170, 850);

	this->OurHpBarOutline.setSize(sf::Vector2f(120.f, 5.f));
	this->OurHpBarOutline.setFillColor(sf::Color::Transparent);
	this->OurHpBarOutline.setOutlineColor(sf::Color::Black);
	this->OurHpBarOutline.setOutlineThickness(1);
	this->OurHpBarOutline.setPosition(180, 895);

	

	winclose->setSize(sf::Vector2f(34.5, 39));
	winclose->setPosition(50, 60);
	winclose->setFillColor(sf::Color::Transparent);
}

void FightMenuState::SetPoke() //set pokemons variables
{
	ennemipoke.chose();	//call this methode to set the entity with Tiplouf stats. call ennemipoke.caninos() to load stats from caninos. 
							//create in EnnemiPoke.cpp as many pokemon as you want then load there stats here like this.
							//pokemon's pp are not loaded here to simplify the fight code, but you can load it here; you'll need to create the code to manage it.

	this->EnnemiMaxHp = ennemipoke.life;
	this->EnnemiCurrentHp = this->EnnemiMaxHp;
	cout << "ennemi max hp :" << EnnemiMaxHp << "\n";

	myPikachu.pikachu();//Our pokemon stats
	this->OurMaxHp = myPikachu.life;
	this->OurCurrentHp = this->OurMaxHp;
	cout << "Our max HP : " << OurMaxHp << "\n";
}

void FightMenuState::UpdateHpBar() {

	this->EnnemiHpBar.setSize(sf::Vector2f(120.f * (this->EnnemiCurrentHp / this->EnnemiMaxHp), 5.f));
	this->EnnemiHpBar.setFillColor(sf::Color(10, 150, 10));
	this->EnnemiHpBar.setPosition(1680, 245);

	this->OurHpBar.setSize(sf::Vector2f(120.f * (this->OurCurrentHp / this->OurMaxHp), 5.f));
	this->OurHpBar.setFillColor(sf::Color(10, 150, 10));
	this->OurHpBar.setPosition(180, 895);
}

void FightMenuState::DmgEnnemiHp(int skillDmg) {
	bool continu = false;
	cout << options[pos] << " !!!!!!!!!!!!!!!!!!!\n";
	cout << " press space 1\n";
	while (!continu) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			this->EnnemiCurrentHp -= skillDmg;//ennemi take dmg
			sleep(milliseconds(1000));
			cout << " Ennemi take " << skillDmg << "Dmg\n";
			sleep(milliseconds(1000));
			cout << " press space 2\n";
			while (!continu) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					textAfterAtk();
					EnnemiAtk();
					cout << " press space 3\n";
					while (!continu) {
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
							cout << "you take " << ennemipoke.dmg << " dmg";
							cout << " press space 4\n";
							while (!continu) {
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
									break;
								}
							}
							break;
						}
					}
					break;
				}
			}
			break;
		}
	}
}
void FightMenuState::EnnemiAtk()//our pokemon take dmg
{

	cout << "ennemi pokemon attack !\n";
	this->OurCurrentHp -= ennemipoke.dmg;
}

void FightMenuState::EnnemiHp() //display ennemi hp
{
	int hp = this->EnnemiCurrentHp;
	this->EnnemiCurrentHpText.setFont(*font);
	this->EnnemiCurrentHpText.setCharacterSize(20);
	this->EnnemiCurrentHpText.setFillColor(sf::Color::Black);
	this->EnnemiCurrentHpText.setString(std::to_string(hp));
	this->EnnemiCurrentHpText.setPosition(1740, 200);
	hp = this->EnnemiMaxHp;
	this->EnnemiMaxHpText.setFont(*font);
	this->EnnemiMaxHpText.setCharacterSize(20);
	this->EnnemiMaxHpText.setFillColor(sf::Color::Black);
	this->EnnemiMaxHpText.setString(std::to_string(hp));
	this->EnnemiMaxHpText.setPosition(1770, 200);
}

void FightMenuState::OurHp() //display our hp
{
	int hp = this->OurCurrentHp;
	this->OurCurrentHpText.setFont(*font);
	this->OurCurrentHpText.setCharacterSize(20);
	this->OurCurrentHpText.setFillColor(sf::Color::Magenta);
	this->OurCurrentHpText.setString(std::to_string(hp));
	this->OurCurrentHpText.setPosition(240, 850);
	hp = this->OurMaxHp;
	this->OurMaxHpText.setFont(*font);
	this->OurMaxHpText.setCharacterSize(20);
	this->OurMaxHpText.setFillColor(sf::Color::Black);
	this->OurMaxHpText.setString(std::to_string(hp));
	this->OurMaxHpText.setPosition(270, 850);
}

void FightMenuState::textAfterAtk() //display text after you attacked
{
	cout << "text after atk\n";
	TextAfterAtk.setFont(*font);
	TextAfterAtk.setFillColor(sf::Color::Black);
	TextAfterAtk.setString("Ennemie pokemon took damage !\n");
	TextAfterAtk.setPosition(200, 100);
	sleep(milliseconds(1000));
	TextAfterAtk.setString("");
	Menu();
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && !theselect) {
		Menu();
	}
	

	if (fightmenu && sf::Keyboard::isKeyPressed(sf::Keyboard::R) && !theselect) {
		if (pos == 0)
		{	
			pos = 0;
			Menu();
			
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {

		sleep(milliseconds(200));
		if (pos == 0 ) {
			if (!fightmenu && !pokemonmenu) {
				Fight();
				cout << "faitooo\n";
			}
		}
		else if (pos == 1) {
			if (!pokemonmenu  && !fightmenu) {
				Pokemon();
				cout << "I PLAY POKEMON GO EVERYDAY\n";
			}
			if (fightmenu)
			{
				DmgEnnemiHp(myPikachu.dmg);
				pos = 0;
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
				DmgEnnemiHp(myPikachu.dmg * 1.2);
				pos = 0;
			}
		}
		else if (pos == 3) {
			if (fightmenu)
			{

				DmgEnnemiHp(myPikachu.dmg * 1.5);
				pos = 0;
			}
		}
		else if (pos == 4) {
			if (fightmenu)
			{
				DmgEnnemiHp(myPikachu.dmg * 2);
				pos = 0;
			}
		}
	}

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

void FightMenuState::UpdateKeybinds(const float& data)
{
	/* Check Quit Input */
	this->CheckForQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->music.setVolume(0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->music.setVolume(50);
	}
}

void FightMenuState::Update(const float& data, int posT)
{
	if (EnnemiCurrentHp <= 0)
	{
		cout << "ennemi vaincu !\n";
		this->states->push(new MainState(this->window, this->states));
		StopMusic();
		EnnemiCurrentHp = 1;
	}
	this->UpdateHpBar();
	this->UpdateKeybinds(data);
	this->EnnemiHp();
	this->OurHp();
	this->loop_events();
}

void FightMenuState::Run()
{
	theselect = true;
	if (rand() % 50 > 25) {
		options = { "You successfully run away" };
		texts.resize(1);
		coords = { {200,900} };

		sizes = { 40 };
		for (std::size_t i{}; i < texts.size(); ++i) {
			texts[i].setFont(*font);
			texts[i].setFillColor(sf::Color::Black);
			texts[i].setString(options[i]);
			texts[i].setCharacterSize(sizes[i]);
			texts[i].setPosition(coords[i]);
		}

		
		
		music.stop();
		this->states->push(new MainState(this->window, this->states));
	}
	else
	{
		options = { "You failed to run away" };
		texts.resize(1);
		coords = { {200,900} };

		sizes = { 40 };
		for (std::size_t i{}; i < texts.size(); ++i) {
			texts[i].setFont(*font);
			texts[i].setFillColor(sf::Color::Black);
			texts[i].setString(options[i]);
			texts[i].setCharacterSize(sizes[i]);
			texts[i].setPosition(coords[i]);
		}
		
		Menu();
	}

void FightMenuState::Update(const float& data, int posT)
{
	if (EnnemiCurrentHp <= 0)
	{
		cout << "ennemi vaincu !\n";
		this->states->push(new MainState(this->window, this->states));
		StopMusic();
		EnnemiCurrentHp = 1;
	}
	this->UpdateKeybinds(data);
	this->EnnemiHp();
	this->OurHp();
	this->loop_events();
}


void FightMenuState::Render(sf::RenderWindow* target)
{
	if (!target)	target = this->window;

	target->draw(*bg);
	target->draw(*myPikachu.pikachuSprite);
	//target->draw(*ennemipoke.CaninosSprite);
	target->draw(*ennemipoke.TiploufSprite);
	target->draw(EnnemiHpBox);
	target->draw(EnnemiHpBar);
	target->draw(EnnemiHpBarOutline);
	target->draw(OurHpBox);
	target->draw(OurHpBar);
	target->draw(OurHpBarOutline);
	target->draw(EnnemiMaxHpText);
	target->draw(EnnemiCurrentHpText);
	target->draw(OurMaxHpText);
	target->draw(OurCurrentHpText);
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


