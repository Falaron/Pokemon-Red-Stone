# include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class TileMap : public Drawable, public Transformable
{
public:
    bool load(const string& tileset, Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
    virtual void draw(RenderTarget& target, RenderStates states) const;

private:
    VertexArray m_vertices;
    Texture m_tileset;
};