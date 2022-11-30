# include "../headers/Game.hpp"

void Game::InitWindow(int width, int height, const char* title)
{

    this->window = new RenderWindow(VideoMode(width, height), title, (Style::Titlebar, Style::Close));
}

void Game::InitStates()
{
    //this->states.push(new MainMenuState(this->window));
    this->states.push(new FightMenuState(this->window));

}

Game::Game()
{
    this->InitWindow(1920, 1080, "Pokemon : Red Stone");
    this->InitStates();
}

Game::~Game()
{
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

void Game::UpdateDeltaTime()
{
    this->deltaTime = this->deltaClock.restart().asSeconds();
}

void Game::Run()
{
    while (this->window->isOpen())
    {
        this->UpdateDeltaTime();
        this->Update();
        this->Render();
    }
}

bool Game::isOpen(void) const
{
    return this->window->isOpen();
}

void Game::Update()
{
    while (this->window->pollEvent(event))
    {
        if (event.type == Event::Closed) {
            this->states.top()->EndState();
            delete this->states.top();
            this->states.pop();
        }


        if (!this->states.empty())
        {
            this->states.top()->Update(this->deltaTime);

            if (this->states.top()->GetQuit())
            {
                this->states.top()->EndState();
                delete this->states.top();
                this->states.pop();
            }
        }
        else this->window->close(); // End Game
    }
}

void Game::Render()
{
    this->window->clear();

    //window.draw(map); //draw map
    //this->window.draw(PlayerSprite);
    if (!this->states.empty()) this->states.top()->Render(this->window);
    this->window->display();
}



