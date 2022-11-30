#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Map {
public:
	Map(const char* map);
	~Map();

	int getHeight() { return height; }
	bool isInfinite() { return infinite; }
	vector<Layer> getLayers(){ return layers; }
	int getNextLayerId() { return nextlayerid; }
	int getNextObjectId() { return nextobjectid; }
	string getOrientation() { return orientation; }
	string getRenderOrder() { return renderorder; }
	string getTiledVersion(){ return tiledversion; }
	int getTileHeight() { return tileheight; }
	vector<TileSetMap> getTileSetMap() { return tilesets; }
	int getTileWidth() { return tilewidth; }
	string getType() { return type; }
	float getVersion() { return version; }
	int getWidth() { return width; }

private: 
	int height;
	bool infinite;
	vector<Layer> layers;
	int nextlayerid;
	int nextobjectid;
	string orientation;
	string renderorder;
	string tiledversion;
	int tileheight;
	vector<TileSetMap> tilesets;
	int tilewidth;
	string type;
	float version;
	int width;
};

class Layer {
public:
	Layer(){};
	Layer(rapidjson::Value& value);
	~Layer();

	vector<int> getData() { return data; }
	int getHeight() { return height; }
	int getId() { return id; }
	string getImage() { return image; }
	string getName() { return name; }
	int getOpacity() { return opacity; }
	string getType() { return type; }
	bool isVisible() { return visible; }
	int getWidth() { return width; }
	int getX() { return x; }
	int getY() { return y; }

private:
	vector<int> data;
	int height;
	int id;
	string image;
	string name;
	int opacity;
	string type;
	bool visible;
	int width;
	int x;
	int y;
};

