#include <sstream>
#include "../headers/TileMap.hpp"

using namespace std;

TileMap::TileMap()
{
}

void TileMap::update()
{
}

void TileMap::loadFile(const string pathToTexture, const string pathToMap)
{
    if (!this->generalTexture.loadFromFile(pathToTexture))
    {
    }

    string data;
    string line;
    fstream file;

    file.open(pathToMap, ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            data += line;
        }
        file.close();
    }
    else
    {
        cout << "ERROR::TILEMAP::LOAD::FILE COULD NOT LOAD FROM FILE::FILENAME: " << pathToMap << endl;
    }

    string tmp;
    vector<int> row;
    vector<vector<int>> layer;

    for (int i = 0; i < data.size(); i++)
    {
        // Create new tile
        if (data[i] == ',')
        {
            if (!tmp.empty())
            {
                int tile = stoi(tmp);
                row.push_back(tile);
                tmp = "";
            }
        }
        // New line of tiles
        else if (data[i] == ';')
        {
            if (row != vector<int>())
            {
                layer.push_back(row);
                row = vector<int>();
            }
        }
        // New layer of tiles
        else if (data[i] == '!')
        {
            if (layer != vector<vector<int>>())
            {
                this->tileMap.push_back(layer);
                layer = vector<vector<int>>();
            }
        }

        else
            tmp += data[i];
    }
}

void TileMap::Render(RenderTarget *target)
{
    Sprite sprite;
    sprite.setTexture(this->generalTexture);

    // Draw TileMap passing by LAYER into Y into X
    for (int layer = 0; layer < this->tileMap.size(); layer++)
    {
        for (int y = 0; y < this->tileMap[layer].size(); y++)
        {
            for (int x = 0; x < this->tileMap[layer][y].size(); x++)
            {
                int tileId = this->tileMap[layer][y][x] - 1;
                if (tileId != -1)
                {
                    sprite.setTextureRect(sf::IntRect(
                        (tileId % 148) * MAP_TILE_SIZE,
                        (tileId / 148) * MAP_TILE_SIZE,
                        16,
                        16));
                    sprite.setPosition(static_cast<float>(x * TILE_SIZE), static_cast<float>(y * TILE_SIZE));

                    sprite.setScale(MAP_TILE_SCALE, MAP_TILE_SCALE);
                    target->draw(sprite);
                }
            }
        }
    }
}

const Vector2f& TileMap::getSizeWorldF() const
{
    return this->SizeWorldF;
}

const Vector2i& TileMap::getSizeWorldGrid() const
{
    return this->SizeWorldGrid;
}

const sf::Texture* TileMap::getTileTexture() const
{
    return &this->tileTexture;
}


TileMap::~TileMap()
{
    // this->clear();
}