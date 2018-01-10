#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#include <SDL.h>

typedef struct {

    SDL_Rect positionTete;
    int orientation; // 0 = bas, 1 = gauche, 2 = droite, 3 = haut
    int lengthQueue;
    SDL_Surface* imgTete;
    SDL_Surface* imgCorps;

    SDL_Rect positionCorps[];
}Snake;

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

#endif // STRUCTURES_H_INCLUDED
