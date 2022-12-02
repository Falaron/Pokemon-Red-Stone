#include "../headers/Game.hpp"
#include "../headers/Config.hpp"

void Game::InitWindow(int width, int height, const char *title)
{

    this->window = new RenderWindow(VideoMode(width, height), title, (Style::Titlebar, Style::Close));
}

void Game::InitStates()
{
    this->states.push(new MainMenuState(this->window, &this->states));
    
    // this->states.push(new MainMenuState(this->window, &this->states));

}

Game::Game()
{
    this->InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pokemon : Red Stone");
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
        if (event.type == Event::Closed)
        {
            this->states.top()->EndState();
            delete this->states.top();
            this->states.pop();
        }
    }

    if (!this->states.empty()) // if state ongoing
    {
        this->states.top()->Update(this->deltaTime, 0, 0); // update state

        if (this->states.top()->GetQuit()) // check if the status has been left
        {
            this->states.top()->EndState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else
        this->window->close(); // End Game
}

void Game::Render()
{
    this->window->clear();
    // window.draw(map); //draw map
    // this->window.draw(PlayerSprite);
    if (!this->states.empty())
        this->states.top()->Render(this->window); // if state ongoin then render it
    this->window->display();
}
