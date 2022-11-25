#include "MainMenuState.hpp"


MainMenuState::MainMenuState(sf::RenderWindow* window/*, std::map<std::string, int>* supportedKeys*/) 
	: State(window)
{
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Blue);
	winclose = new sf::RectangleShape();
	font = new sf::Font();
	image = new sf::Texture();
	bg = new sf::Sprite();


	set_values();
}

MainMenuState::~MainMenuState()
{
	delete winclose;
	delete font;
	delete image;
	delete bg;
}

void MainMenuState::set_values() {

	pos = 0;
	pressed = theselect = false;
	font->loadFromFile("font\\Roboto\\Roboto-Bold.ttf");
	image->loadFromFile("sprites\\uwubg.jpg");

	bg->setTexture(*image);

	bg->setScale(1, 1);
	/*
	pos_mouse = { 0,0 };
	mouse_coord = { 0, 0 };
	*/
	options = { "Pokemon : Red Stone", "Play", "Options", "About", "Quit" };
	texts.resize(5);
	coords = { {200, 900},{200,180},{200,270},{200,360},{200,450} };
	sizes = { 30,42,36,36,36 };

	for (std::size_t i{}; i < texts.size(); ++i) {
		texts[i].setFont(*font);
		texts[i].setString(options[i]);
		texts[i].setCharacterSize(sizes[i]);
		texts[i].setOutlineColor(sf::Color::Magenta);
		texts[i].setPosition(coords[i]);
	}
	texts[1].setOutlineThickness(10);
	pos = 1;

	winclose->setSize(sf::Vector2f(34.5, 39));
	winclose->setPosition(50, 60);
	winclose->setFillColor(sf::Color::Transparent);

}

void MainMenuState::loop_events() {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
      if( pos < 4){
        ++pos;
        pressed = true;
        texts[pos].setOutlineThickness(10);
        texts[pos - 1].setOutlineThickness(0);
        pressed = false;
        theselect = false;
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
      if( pos > 1){
        --pos;
        pressed = true;
        texts[pos].setOutlineThickness(10);
        texts[pos + 1].setOutlineThickness(0);
        pressed = false;
        theselect = false;
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect){
      theselect = true;
      if( pos == 4){
        window->close();
      }
      std::cout << options[pos] << '\n';
    }
}


void MainMenuState::UpdateKeybinds(const float& data)
{
	/* Check Quit Input */
	this->CheckForQuit();

	/* Player Movement Input */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) cout << "I move Left\n";	// this->player.move(deltaTime, move Value Left)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) cout << "I move Right\n";	// this->player.move(move Value Right)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) cout << "I move Up\n";		// this->player.move(move Value Up)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) cout << "I move Down\n";	// this->player.move(move Value Down)
}

void MainMenuState::Update(const float& data)
{
	this->UpdateKeybinds(data);
	this->loop_events();
}

void MainMenuState::Render(sf::RenderWindow* target)
{

	if (!target)	target = this->window;

	//target->draw(this->background);
	target->draw(*bg);
	for (auto t : texts) {
		target->draw(t);
	}


	/*
	if (tileMap)
	{
		std::cout << "--------test i'm here\n";
		target->draw(*tileMap);
		this->tileMap->draw(*target, sf::RenderStates::Default);
	}
	*/


}


void MainMenuState::EndState()
{
	cout << "Main State end\n";
}
