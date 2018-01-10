#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#include <SDL.h>
#include <string.h>

#include "utility.h"
#include "structures.h"



SDL_Surface* LoadImage32(const char* fichier_image);

Map* ChargerMap(const char* fic);
int AfficherMap(Map* m,SDL_Surface* screen);
int LibererMap(Map* m);

void AfficherSnake(Snake* snake, SDL_Surface* screen);


#endif // RENDER_H_INCLUDED
