#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include "State.hpp"

class MainMenuState :
    public State
{

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
protected:
	void set_values();
	void loop_events();
	void draw_all();

private:
    //void initKeybinds();
	sf::RectangleShape background;

public:
    MainMenuState(sf::RenderWindow* window/*, std::map<std::string, int>* supportedKeys*/);
	virtual ~MainMenuState();

	void Update(const float& data);
	void UpdateKeybinds(const float& data);
	void Render(sf::RenderWindow* target = nullptr);

	void EndState();

};

#endif

