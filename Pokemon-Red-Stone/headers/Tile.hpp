#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

enum TileTypes
{
    DEFAULT = 0,
    WALKABLE = 1,
    POKEMONABLE = 2,
    BLOCKED = 3
};

class Tile
{
private:
protected:
    RectangleShape sprite;
    short type;
    bool collision;

public:
    Tile();
    Tile(unsigned gridSizeF, unsigned gridX, unsigned gridY, const Texture &texture, const IntRect &textureRect,
         bool collision = false, short type = TileTypes::DEFAULT);
    virtual ~Tile();

    const bool &getCollision() const;
    const string getAsString() const;

    void update();
    void render(RenderTarget &target);
};
