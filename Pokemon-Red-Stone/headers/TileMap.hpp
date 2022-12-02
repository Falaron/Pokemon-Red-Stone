#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class TileMap
// : public Drawable, public Transformable
{
public:
    TileMap();
    /*TileMap(const string path);
    TileMap(float gridSize, unsigned char width, unsigned char height, string tileTexture);*/
    virtual ~TileMap();

    // void loadFile(string path);
    // void loadFile(const string pathToTexture, const string pathToMap);

    // Getters
    const Vector2f &getSizeWorldF() const;
    const Vector2i &getSizeWorldGrid() const;
    const Texture *getTileTexture() const;  
    // const int getMapSize() const;
    vector<vector<vector<int>>> getTileMap() const;

    void loadFile(const string pathToTexture, const string pathToMap);

    void update();
    /*void Render(RenderWindow* window);*/
    void Render(RenderTarget *target);

    // bool load(const string &tileset, Vector2u tileSize, const int *tiles, unsigned int width, unsigned int height);
    // virtual void draw(RenderTarget &target, RenderStates states) const;

private:
    int TILE_SIZE = 32;
    int MAP_TILE_SIZE = 16;
    int MAP_TILE_SCALE = (TILE_SIZE / MAP_TILE_SIZE);

    Vector2i SizeWorldGrid;
    Vector2f SizeWorldF;

    vector<vector<vector<int>>> tileMap;
    sf::Texture generalTexture;
    sf::Texture natureTexture;

    VertexArray m_vertices;
    Texture tileTexture;
    string tileTextureFile;

    /*void clear();
    void saveFile(const std::string path);*/
};