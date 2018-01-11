#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#include <SDL.h>
#include <string.h>

#include "utility.h"
#include "structures.h"

// Prototype de la surface SDL
SDL_Surface* LoadImage32(const char* fichier_image);

// Prototype de la map
Map* ChargerMap(const char* fic);

// Prototype de render de la map
int AfficherMap(Map* m,SDL_Surface* screen);

// Lib�re la map de la m�moire
int LibererMap(Map* m);

#endif // RENDER_H_INCLUDED
