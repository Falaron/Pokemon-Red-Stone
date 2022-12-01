#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
# include "MainState.hpp"

class MainMenuState :
    public State
{
private:
	sf::Event event;

	int pos;
	bool theselect;
	sf::RectangleShape* winclose;
	sf::Font* font;
	sf::Texture* image;
	sf::Sprite* bg;

	std::vector<const char*> options;
	std::vector<sf::Vector2f> coords;
	std::vector<sf::Text> texts;
	std::vector<std::size_t> sizes;

	sf::RectangleShape background;

	/* SOUND */
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::Music music;

public:
    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~MainMenuState();

	void SetValues();
	void Update(const float& dt, int posT);
	void UpdateKeybinds(const float& dt);
	void Render(sf::RenderWindow* target = nullptr);

	void EndState();

};

#endif

