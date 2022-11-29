# include "MainState.hpp"
# include "FightMenuState.hpp"

MainState::MainState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states), tileMap(nullptr)
{
	
    // this->tileMap = nullptr;
    //  TileMap(&"res/tileset.png", sf::Vector2u(32,32), 32, 32);
}

MainState::~MainState()
{

}


void MainState::UpdateKeybinds(const float& dt)
{
	/* Check Quit Input */
	this->CheckForQuit();
	this->player.Update(dt, 0);
	/* Player Movement Input */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
		
	{
		this->player.Move(dt, -1.f, 0.f);
		this->player.Update(dt, 64); 
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
	{
		this->player.Move(dt, 1.f, 0.f);
		this->player.Update(dt, 128); 
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
	{
		this->player.Move(dt, 0.f, -1.f);
		this->player.Update(dt, 192); 
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
	{
		this->player.Move(dt, 0.f, 1.f);
		this->player.Update(dt, 0);
	}
	
	

	/* FIGHT TRIGGER */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) this->states->push(new FightMenuState(this->window, this->states));
}

void MainState::Update(const float& dt,int posT)
{
	this->UpdateKeybinds(dt);
	this->InitTextures();
	//this->player.Update(dt,posT);

}

void MainState::Render(sf::RenderWindow *target)
{

    if (tileMap)
    {
        std::cout << "--------test i'm here\n";
        target->draw(*tileMap);
        this->tileMap->draw(*target, sf::RenderStates::Default);
    }

	this->player.Render(target);
}

void MainState::InitTextures()
{
	
}


void MainState::EndState()
{
	cout << "Main State end\n";
}
