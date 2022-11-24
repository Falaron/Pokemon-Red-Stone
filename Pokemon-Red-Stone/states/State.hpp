# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>
# include <SFML/System.hpp>
# include <SFML/Audio.hpp>

# include <ctime>
# include <map>
# include <stack>
# include <iostream>
using namespace std;
using namespace sf;

class State {
public:
	State(sf::RenderWindow* window);
	virtual ~State();

	virtual void Render(sf::RenderWindow* target = nullptr) = 0;
	virtual void Update(const float& data) = 0;
	virtual void UpdateKeybinds(const float& data) = 0;

	virtual void CheckForQuit();
	const bool& GetQuit() const;

	virtual void EndState() = 0;

private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;

	bool quit;
};