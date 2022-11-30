#include <sstream>
#include "../headers/TileMap.hpp"


using namespace std;
TileMap::TileMap(float gridSize, unsigned char width, unsigned char height, string tileTextureFile)
{
    // this->gridSizeF = gridSizeF;
    // this->gridSizeI = static_cast<int>(this->gridSizeF);
    // this->SizeWorldGrid = Vector2i(width, height);
    // this->SizeWorldF = static_cast<float>(width) * gridSize;
    // this->SizeWorldF = static_cast<float>(height) * gridSize;
    // this->layers = 1;
    // this->tileTextureFile = tileTextureFile;

    // this->tileMap.resize(this->SizeWorldGrid.x, vector<vector<vector<Tile *>>>());
    // for (size_t x = 0; x < this->SizeWorldGrid.x; x++)
    // {
    //     for (size_t y = 0; y < this->SizeWorldGrid.y; y++)
    //     {
    //         this->tileMap[x].resize(this->SizeWorldGrid.y, vector<vector<Tile *>>());

    //         for (size_t z = 0; z < this->layers; z++)
    //         {
    //             this->tileMap[x][y].resize(this->layers, vector<Tile *>());
    //         }
    //     }
    // }
    // if (!this->tileTexture.loadFromFile(tileTextureFile))
    // {
    //     cout << "ERROR::TILEMAP::FAILED_TO_LOAD_TILE_TEXTURE_FILE::FILENAME: " << tileTextureFile << endl;
    // }
}

TileMap::TileMap(const string path)
{
    // this->loadFile(pathToTexture, pathToMap);
}

void TileMap::update()
{
}

// void TileMap::clear()
// {
//     if (!this->tileMap.empty())
//     {
//         for (size_t x = 0; x < this->SizeWorldGrid.x; x++)
//         {
//             for (size_t y = 0; y < this->SizeWorldGrid.y; y++)
//             {
//                 for (size_t z = 0; z < this->layers; z++)
//                 {
//                     for (size_t w = 0; w < this->layers; w++)
//                     {
//                         if (this->tileMap[x][y][z][w] != NULL)
//                         {
//                             delete this->tileMap[x][y][z][w];
//                             this->tileMap[x][y][z][w] = NULL;
//                         }
//                     }
//                     this->tileMap[x][y][z].clear();
//                 }
//                 this->tileMap[x][y].clear();
//             }
//             this->tileMap[x].clear();
//         }
//         this->tileMap.clear();
//     }
//     cout << "TileMap size : " << this->tileMap.size() << endl;
// }

// void TileMap::saveFile(const string path)
// {
//     /*Saves the entire tilemap to a text-file.
//     Format:
//     Basic:
//     Size x y
//     gridSize
//     layers
//     texture file
//     All tiles:
//     type
//     gridPos x y layer
//     Texture rect x y
//     collision
//     tile_specific...
//     */

//     ofstream out_file;

//     out_file.open(path);

//     if (out_file.is_open())
//     {
//         out_file << this->SizeWorldGrid.x << " " << this->SizeWorldGrid.y << endl
//                  << this->gridSizeI << endl
//                  << this->layers << endl
//                  << this->tileTextureFile << endl;

//         for (int x = 0; x < this->SizeWorldGrid.x; x++)
//         {
//             for (int y = 0; y < this->SizeWorldGrid.y; y++)
//             {
//                 for (int z = 0; z < this->layers; z++)
//                 {
//                     if (!this->tileMap[x][y][z].empty())
//                     {
//                         for (size_t w = 0; w < this->tileMap[x][y][z].size(); w++)
//                         {
//                             out_file << x << " " << y << " " << z << " " << this->tileMap[x][y][z][w]->getAsString()
//                                      << " ";
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     else
//     {
//         cout << "ERROR::TILEMAP::COULD NOT SAVE TO FILE::FILENAME: " << path << "\n";
//     }

//     out_file.close();
// }

void TileMap::loadFile(const string pathToTexture, const string pathToMap)
{

    this->generalTexture.loadFromFile(pathToTexture);
    // this->generalTexture.setSmooth(true);

    string data;
    string line;
    fstream file;

    file.open(pathToMap);
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
    vector<vector<int>> layer = vector<vector<int>>();

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
void TileMap::render(RenderTarget &target)
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
                    // définir getPosition
                    // sprite.setPosition(
                    // 	static_cast<float>(this->player.getPosition().x + (x + 0.5) * TILE_SIZE),
                    // 	static_cast<float>(this->player.getPosition().y + y * TILE_SIZE)
                    // );
                    sprite.setScale(MAP_TILE_SCALE, MAP_TILE_SCALE);
                    target.draw(sprite); // jsp ?
                }
            }
        }
    }

    // Draw player ?

    // for (auto &x : this->tileMap)
    // {
    //     for (auto &y : x)
    //     {
    //         for (auto *z : y)
    //         {
    //             if (z)
    //             {
    //                 z->render(target);
    //             }
    //         }
    //     }
    // }
}

const Vector2f &TileMap::getSizeWorldF() const
{
    return this->SizeWorldF;
}

const Vector2i &TileMap::getSizeWorldGrid() const
{
    return this->SizeWorldGrid;
}

const sf::Texture *TileMap::getTileTexture() const
{
    return &this->tileTexture;
}

TileMap::~TileMap()
{
    // this->clear();
}