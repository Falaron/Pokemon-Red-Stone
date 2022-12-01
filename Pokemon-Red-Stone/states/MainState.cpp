
# include "MainState.hpp"
# include "FightMenuState.hpp"
# include "../headers/Config.hpp"


MainState::MainState(sf::RenderWindow *window, std::stack<State *> *states)
    : State(window, states)
{
    this->dir = 0;
    InitMusic("musics/ingame.wav");
    InitTiles();
}

MainState::~MainState()
{
}

void MainState::InitTiles()
{
	
	this->tileMap.loadFile("sprites/global.png", "src/map/map.map");//load map
	
}

void MainState::UpdateKeybinds(const float &dt)
{
	/* Check Quit Input */
	this->CheckForQuit();
	this->player.Update(dt, 0);//Update the player's sprite
	float movX = 1;//player speed X axis
	float movY = 1;//player speed Y axis

	/* Player Movement Input */
	if (LEFT) //Bind are defined in Config.hpp
	{
		this->dir = 64;//Sprite is 64x64 for per frame.-------------Ajust this setting depending of the imaged used for Player's sprite
		this->player.Move(dt, movX * -1, movY * 0);//move the player
		this->player.Update(dt, dir);
	}
	else if (RIGHT) 
	{
		this->dir = 128; // -------------Ajust this setting depending of the imaged used for Player's sprite
		this->player.Move(dt, movX, movY * 0);
		this->player.Update(dt, dir);
	}
	else if (UP) 
	{
		this->dir = 192; // -------------Ajust this setting depending of the imaged used for Player's sprite
		this->player.Move(dt, movX * 0, movY * -1);
		this->player.Update(dt,dir);
	}
	else if (DOWN) 
	{
		this->dir = 0; // -------------Ajust this setting depending of the imaged used for Player's sprite
		this->player.Move(dt, movX * 0, movY);
		this->player.Update(dt,dir);
	}
	else {
		this->player.isMoving = false;
		this->player.shape.setTextureRect(sf::IntRect(0, this->dir, 64, 64));	//Set the sprite to the idle frame.
																				//Ajust this setting depending of the imaged used for Player's sprite
	}

	//Run system
	if (SHIFT) this->player.ChangeSpeed(250.f);
	else this->player.ChangeSpeed(100.f);


	/* FIGHT TRIGGER */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))//use for testing. Press F to start fight with another pokemon
	{
		// StopMusic();
		this->states->push(new FightMenuState(this->window, this->states));//start Fight menu state
	}
}

void MainState::Update(const float &dt, int posT)
{
    this->UpdateKeybinds(dt);
}

void MainState::Render(sf::RenderWindow *target)
{
    this->tileMap.Render(target);
    this->player.Render(target);
}

void MainState::EndState()
{
    cout << "Main State end\n";
}
