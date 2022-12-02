#include <SFML/Graphics.hpp>
class Tile
{
private:
    sf::RectangleShape sprite;
protected:

public:
    Tile(float gridSizeF, float x, float y, sf::Texture& texture, sf::IntRect& textureRect);
    virtual ~Tile();

    void update();
    void render(sf::RenderTarget &target);
};



