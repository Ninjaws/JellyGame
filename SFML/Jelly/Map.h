#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Game.h"

class Map : virtual public Game
{
public:
	Map();
	~Map();

		// DrawMap - Draws the tilemap to the screen
	void DrawMap();
		// LoadMap - Loads the tilemap from a textfile into the 'map' variable
	void LoadMap();
		// LoadColMap - Loads the collision map from a textfile into the 'colMap' variable
	void LoadColMap();	

		// SetMapLocation - Sets the directory of the tile map
		// @param string - Directory of the tilemap
	void SetMapLocation(std::string map);
		// SetColMapLocation - Sets the directory of the collision map
		// @param string - Directory of the collision map
	void SetColMapLocation(std::string colmap);		

		// GetTileSize - Returns the tile width and height
	const float GetTileSize();
		// GetColMap - Returns the collision map
	const std::vector < std::vector<int>> GetColMap();		

private:
	std::vector<std::vector<sf::Vector2i>> map;		// Holds the number for every single tile, which refers to a certain sprite in the tileset
	std::vector<std::vector<int>> colMap;			// Holds 1s (collision) and 0s (no collision) for every tile  
	std::string mapLocation;						// Holds the location of the map
	std::string colMapLocation;						// Holds the location of the collision map
	sf::Texture tileTexture;						// Loads the sprites used for the tiles
	sf::Sprite tileSprites;							// Holds the sprites used for the tiles
	
	const float tileSize = 32;						// Holds the width and height of the tiles
};

#endif

