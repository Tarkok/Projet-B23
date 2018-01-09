#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#include <SDL.h>
#include <string.h>

#include "utility.h"
#include "character.h"

/*Fonction de gestion des images*/

//Charge une image dans la ram puis dans une variable
SDL_Surface* LoadImage(const char* filePath);
//Stocke les different tile du tileSet dans le tableau de la carte
void loadMapTileSet(FILE* filePath, Map* carte);

/*Fonction de rendu de la carte*/
Map* loadMap(const char* filePath);
int drawMap(Map* carte, SDL_Surface* screen);
int clearMap(Map* carte);

/*Fonction de rendu de character*/

#endif // RENDER_H_INCLUDED
