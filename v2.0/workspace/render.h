#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#include <SDL.h>
#include <string.h>

#include "utility.h"
#include "character.h"

typedef unsigned char tileindex;

typedef struct
{
	SDL_Rect R;
	int plein;

} TileProp;

typedef struct
{
	int LARGEUR_TILE,HAUTEUR_TILE;
	int nbtilesX,nbtilesY;
	SDL_Surface* tileset;
	TileProp* props;
	tileindex** schema;
	int nbtiles_largeur_monde,nbtiles_hauteur_monde;
} Map;

Map* ChargerMap(const char* fic);
int AfficherMap(Map* m,SDL_Surface* screen);
int LibererMap(Map* m);


#endif // RENDER_H_INCLUDED
