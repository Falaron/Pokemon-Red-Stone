#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
# include "MainState.hpp"

class MainMenuState :
    public State
{
private:
	int pos;
	bool pressed, theselect;
	sf::RectangleShape* winclose;
	sf::Font* font;
	sf::Texture* image;
	sf::Sprite* bg;

	std::vector<const char*> options;
	std::vector<sf::Vector2f> coords;
	std::vector<sf::Text> texts;
	std::vector<std::size_t> sizes;

	sf::RectangleShape background;

public:
    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states/*, std::map<std::string, int>* supportedKeys*/);
	virtual ~MainMenuState();

	void SetValues();
	void Update(const float& data);
	void UpdateKeybinds(const float& data);
	void Render(sf::RenderWindow* target = nullptr);

	void EndState();

};

#endif

