#ifndef TILE_H
#define TILE_H

#include "Entity.h"

enum TILE_TYPES
{
	NO_TILE,
	GRASS_TILE
};

class Tile
{
	private:
	
		TILE_TYPES type;
		
		Entity *entity;
	
	public:
	
//========================= CONSTRUCTORS & DESTRUCTORS =========================
	
		Tile(TILE_TYPES _type = NO_TILE);
		
		virtual ~Tile();
};

#endif // TILE_H