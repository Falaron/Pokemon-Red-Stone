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
	// InitMusic("musics/ingame.wav");
	InitTiles();
	window->setKeyRepeatEnabled(true);
}

MainState::~MainState()
{

}

void MainState::InitTiles()
{
	
	this->tileMap.loadFile("sprites/tiles.png", "src/map/map.map");
	
}

void MainState::UpdateKeybinds(const float& dt)
{
	/* Check Quit Input */
	this->CheckForQuit();
	this->player.Update(dt, 0);
	float movX = 1.f;
	float movY = 1.f;
	/* Player Movement Input */
	if (LEFT) 
	{
		this->dir = 64;
		this->player.Move(dt, movX * -1, movY * 0);
		this->player.Update(dt, dir);
	}
	else if (RIGHT) 
	{
		this->dir = 128;
		this->player.Move(dt, movX, movY * 0);
		this->player.Update(dt, dir);
	}
	else if (UP) 
	{
		this->dir = 192;
		this->player.Move(dt, movX * 0, movY * -1);
		this->player.Update(dt,dir);
	}
	else if (DOWN) 
	{
		this->dir = 0;
		this->player.Move(dt, movX * 0, movY);
		this->player.Update(dt,dir);
	}
	/*else if (UP && RIGHT)
	{
		this->dir = 192;
		this->player.Move(dt, movX / 4, -movY / 4);
		this->player.Update(dt, dir);
	}
	else if (UP && LEFT)
	{
		this->dir = 192;
		this->player.Move(dt, -movX / 4, -movY / 4);
		this->player.Update(dt, dir);
	}
	else if (DOWN && RIGHT)
	{
		this->dir = 0;
		this->player.Move(dt, movX / 4, movY / 4);
		this->player.Update(dt, dir);
	}
	else if (DOWN && LEFT)
	{
		this->dir = 0;
		this->player.Move(dt, -movX / 4, movY / 4);
		this->player.Update(dt, dir);
	}*/
	else {
		this->player.isMoving = false;
		this->player.shape.setTextureRect(sf::IntRect(0, this->dir, 64, 64));
	}

	/* FIGHT TRIGGER */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		// StopMusic();
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
