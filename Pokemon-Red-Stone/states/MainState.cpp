# include "MainState.hpp"
# include "FightMenuState.hpp"
# define LEFT sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
# define RIGHT sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
# define UP sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
# define DOWN sf::Keyboard::isKeyPressed(sf::Keyboard::Down)

MainState::MainState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states)
{
	this->dir=0;
    //  TileMap(&"res/tileset.png", sf::Vector2u(32,32), 32, 32);
	InitMusic("musics/ingame.wav");
	InitTiles();
}

MainState::~MainState()
{

}

void MainState::InitTiles()
{
	
	this->tileMap.loadFile("sprites/tiles.png", "src/map/spawn.map");
	
}

void MainState::UpdateKeybinds(const float& dt)
{
	/* Check Quit Input */
	this->CheckForQuit();
	this->player.Update(dt, 0);
	/* Player Movement Input */
	if (LEFT) 
	{
		this->dir = 64;
		this->player.Move(dt, -1.f, 0.f);
		this->player.Update(dt, dir);
		
	}
	else if (RIGHT) 
	{
		this->dir = 128;
		this->player.Move(dt, 1.f, 0.f);
		this->player.Update(dt, dir);
		
	}
	else if (UP) 
	{
		this->dir = 192;
		this->player.Move(dt, 0.f, -1.f);
		this->player.Update(dt,dir);
		
	}
	else if (DOWN) 
	{
		this->dir = 0;
		this->player.Move(dt, 0.f, 1.f);
		this->player.Update(dt,dir);
	}
	else if (UP && RIGHT)
	{
		this->dir = 192;
		this->player.Move(dt, 0.25, -0.25);
		this->player.Update(dt, dir);
	}
	else if (UP && LEFT)
	{
		this->dir = 192;
		this->player.Move(dt, -0.25, -0.25);
		this->player.Update(dt, dir);
	}
	else if (DOWN && RIGHT)
	{
		this->dir = 0;
		this->player.Move(dt, 0.25, 0.25);
		this->player.Update(dt, dir);
	}
	else if (DOWN && LEFT)
	{
		this->dir = 0;
		this->player.Move(dt, -0.25, 0.25);
		this->player.Update(dt, dir);
	}
	else {
		this->player.isMoving = false;
		this->player.shape.setTextureRect(sf::IntRect(0, this->dir, 64, 64));
		//this->player.Update(dt, this->dir);

	}

	/* FIGHT TRIGGER */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		StopMusic();
		this->states->push(new FightMenuState(this->window, this->states));
	}
}

void MainState::Update(const float& dt,int posT)
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
