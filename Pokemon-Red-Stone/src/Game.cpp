# include "../headers/Game.hpp"

void Game::InitWindow(int width, int height, const char* title)
{

    this->window = new RenderWindow(VideoMode(width, height), title, (Style::Titlebar, Style::Close));
    this->window->setFramerateLimit(30);
}

void Game::InitStates()
{
    this->states.push(new MainState(this->window));
}

Game::Game()
{
    this->InitWindow(800, 500, "Pokemon : Red Stone");
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

void Game::Run()
{
    while (this->window->isOpen())
    {
        this->UpdateDeltaTime();
        this->Update();
        this->Render();
    }
}

void Game::Update()
{
    while (this->window->pollEvent(event))
    {
        if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
            this->window->close();
    }

    if (!this->states.empty()) this->states.top()->Update(this->deltaTime);
}

void Game::Render()
{
    this->window->clear();
 
    if (!this->states.empty()) this->states.top()->Render(this->window);

    this->window->display();
}

void Game::UpdateDeltaTime()
{
    this->deltaTime = this->deltaClock.getElapsedTime().asSeconds();
}
