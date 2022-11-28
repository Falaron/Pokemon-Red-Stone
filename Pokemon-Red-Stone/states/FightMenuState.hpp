#ifndef FightMenuState_H
#define FightMenuState_H
# include "MainState.hpp"

class FightMenuState :
	public State
{

	int pos;
	bool pressed, theselect;
	sf::RectangleShape* winclose;
	sf::Font* font;
	sf::Texture* image;
	sf::Sprite* bg;
	sf::Event event;

	sf::Vector2i pos_mouse;
	sf::Vector2f mouse_coord;

	std::vector<const char*> options;
	std::vector<sf::Vector2f> coords;
	std::vector<sf::Text> texts;
	std::vector<std::size_t> sizes;
protected:
	void set_values();
	void loop_events();

private:
	//void initKeybinds();
	sf::RectangleShape background;

public:
	FightMenuState(sf::RenderWindow* window, std::stack<State*>* states/*, std::map<std::string, int>* supportedKeys*/);
	virtual ~FightMenuState();

	void Update(const float& data);
	void UpdateKeybinds(const float& data);
	void Render(sf::RenderWindow* target = nullptr);
	void Fight();
	void Pokemon();
	void Run();
	void EndState();

};

#endif

