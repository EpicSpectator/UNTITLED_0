#include "Map.h"

Map::Map(const std::string &filename)
{
	std::ifstream file(filename);

	while(file)
	{
		file >> width >> height;

		tiles = new Tile[width * height];

		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				int n = (((width - 1) - x) + (y * width));

				int type;
				file >> type;

				tiles[n] = new Tile(type);
			}
		}
	}
	
	file.close();
}

Map::~Map()
{
	delete tiles;
	tiles = nullptr;
}