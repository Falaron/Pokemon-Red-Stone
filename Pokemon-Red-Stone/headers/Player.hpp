# include <iostream>
# include <SFML/Graphics.hpp>

class Player {
public:
	void Input();
	void PrintPlayer(const std::string& tileset);
private:
	int positionX = 0;
	int positionY = 0;
	int speed = 5;
};