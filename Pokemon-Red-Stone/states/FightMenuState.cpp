#pragma once
#include <stdlib.h>
#include "FightMenuState.hpp"
#include "../headers/Game.hpp"
#include "../headers/Pikachu.hpp"
#include "../headers/EnnemiPoke.hpp"
#include "../headers/Config.hpp"
#include "../headers/Entity.hpp"

using namespace std;

EnnemiPoke ennemipoke = EnnemiPoke(ennemipoke.imageTiplouf);//create entity(pokemon). this one will be ennemi pokemon
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
	//imagePikachu.loadFromFile(PIKACHU_TEXTURE_PATH);
	//imageTiplouf.loadFromFile("sprites\\tiplouf.png");
	//imagee.loadFromFile(TIPLOUF_TEXTURE_PATH);

	bg->setTexture(*image);
	bg->setScale(1, 1);

	//pikachu->setTexture(imagePikachu);
	//pikachu->setPosition(sf::Vector2f(350, 450)); // position absolue

	
	SetPoke();
	Menu();
	texts[0].setOutlineThickness(10);
	pos = 0;

	winclose->setSize(sf::Vector2f(34.5, 39));
	winclose->setPosition(50, 60);
	winclose->setFillColor(sf::Color::Transparent);
}

void FightMenuState::SetPoke() //set pokemons variables
{
	ennemipoke.caninos();	//call this methode to set the entity with Tiplouf stats. call ennemipoke.caninos() to load stats from caninos. 
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

void FightMenuState::DmgEnnemiHp(int skillDmg) {
	this->EnnemiCurrentHp -= skillDmg;//ennemi take dmg
}

void FightMenuState::EnnemiHp() //display ennemi hp
{
	int hp = this->EnnemiCurrentHp;
	this->EnnemiHpText.setFont(*font);
	this->EnnemiHpText.setFillColor(sf::Color::Black);
	this->EnnemiHpText.setString(std::to_string(hp));
	this->EnnemiHpText.setPosition(800, 200);
}

void FightMenuState::OurHp() //display our hp
{
	int hp = this->OurCurrentHp;
	this->OurHpText.setFont(*font);
	this->OurHpText.setFillColor(sf::Color::Magenta);
	this->OurHpText.setString(std::to_string(hp));
	this->OurHpText.setPosition(800, 600);
}

void FightMenuState::textAfterAtk() //display text after you attacked
{
	cout << "text after atk\n";
	TextAfterAtk.setFont(*font);
	TextAfterAtk.setFillColor(sf::Color::Black);
	TextAfterAtk.setString("Ennemie pokemon took damage !\n");
	TextAfterAtk.setPosition(200, 100);
	sleep(milliseconds(1500));
	TextAfterAtk.setString("");
	Menu();
}

void FightMenuState::textReturnToMenu() // text when you return to the fight menu
{
	cout << "text return\n";
	TextReturnToMenu.setFont(*font);
	TextReturnToMenu.setFillColor(sf::Color::Black);
	TextReturnToMenu.setString("Return\n");
	TextReturnToMenu.setPosition(200, 100);
	sleep(milliseconds(1000));
	TextReturnToMenu.setString("");
	Menu();
}

void FightMenuState::EnnemiAtk()//our pokemon take dmg
{
	cout << "ennemi pokemon attack !\n";
	this->OurCurrentHp -= ennemipoke.dmg + rand() % 5;
	sleep(milliseconds(1000));
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
				
				DmgEnnemiHp(myPikachu.dmg);
				cout << options[1] << " !!!!!!!!!!!!!!!!!!!\n";
				pos = 0;
				textAfterAtk();
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

				DmgEnnemiHp(myPikachu.dmg * 1.2);
				cout << options[2] << " !!!!!!!!!!!!!!!!!!!\n";
				pos = 0;
				textAfterAtk();
				EnnemiAtk();
			}
		}
		else if (pos == 3) {
			if (fightmenu)
			{

				DmgEnnemiHp(myPikachu.dmg * 1.5);
				cout << options[3] << " !!!!!!!!!!!!!!!!!!!\n";
				pos = 0;
				textAfterAtk();
				EnnemiAtk();
			}
		}
		else if (pos == 4) {
			if (fightmenu)
			{

				DmgEnnemiHp(myPikachu.dmg * 1.2);
				cout << options[4] << " !!!!!!!!!!!!!!!!!!!\n";
				pos = 0;
				textAfterAtk();
				EnnemiAtk();
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
	this->UpdateKeybinds(data);
	this->EnnemiHp();
	this->OurHp();
	this->loop_events();
}

void FightMenuState::Run()
{
	theselect = true;
	if (rand() % 50 >49) {
		options = { "You successfully run away" };
		texts.resize(1);
		coords = {{200,900}};

		sizes = {40};
		for (std::size_t i{}; i < texts.size(); ++i) {
			texts[i].setFont(*font);
			texts[i].setFillColor(sf::Color::Black);
			texts[i].setString(options[i]);
			texts[i].setCharacterSize(sizes[i]);
			texts[i].setPosition(coords[i]);
		}

		//this->states->push(new MainState(this->window, this->states));
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
		//Menu();
	}

}

void FightMenuState::Render(sf::RenderWindow* target)
{
	if (!target)	target = this->window;

	target->draw(*bg);
	target->draw(*myPikachu.pikachuSprite);
	//target->draw(*ennemipoke.CaninosSprite);
	target->draw(*ennemipoke.TiploufSprite);
	target->draw(EnnemiHpText);
	target->draw(OurHpText);
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


