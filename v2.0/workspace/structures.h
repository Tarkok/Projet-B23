#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#include <SDL.h>

typedef struct {

    SDL_Rect positionTete;
    int orientation; // 0 = bas, 1 = gauche, 2 = droite, 3 = haut
    int lengthQueue;
    unsigned int positionX;
    unsigned int positionY;
    SDL_Surface* imgTete;
    SDL_Surface* imgCorps;

    SDL_Rect positionCorps[];
}Snake;

typedef unsigned char tileindex;

typedef struct
{
	SDL_Rect R;
	int type; // 0 = vide, 1 = Mortelle, 2 bonus, 3 super bonus, 4 malus

} TileProp;

typedef struct
{
	int LARGEUR_TILE,HAUTEUR_TILE;
	int nbtilesX,nbtilesY;
	SDL_Surface* tileset;
	TileProp* props;
	tileindex** schema;
	int nbtiles_largeur_monde,nbtiles_hauteur_monde;

	int nbFruit;
} Map;

#endif // STRUCTURES_H_INCLUDED
