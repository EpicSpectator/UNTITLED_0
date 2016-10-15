#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <string>

#include "Tile.h"

class Map
{
	private:
	
		Tile *tiles;
	
		unsigned int width;
		unsigned int height;
	
	public:
	
//========================= CONSTRUCTORS & DESTRUCTORS =========================
	
		Map(const std::string &filename);
		
		virtual ~Map();
		
//==================================== GETS ====================================
		
		inline unsigned int getWidth(){ return width; }
		inline unsigned int getHeight(){ return height; }
		
		inline Tile & getTile(int x, int y){ tiles[]; }
};

#endif // MAP_H