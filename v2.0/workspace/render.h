#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#include <SDL.h>
#include <SDL_ttf.h>
#include <string.h>
#include <time.h>

#include "utility.h"
#include "structures.h"

// Prototype de la surface SDL
SDL_Surface* LoadImage32(const char* fichier_image);

// Prototype de la map
Map* ChargerMap(const char* fic);

// Prototype des focntions de rendu de la carte
int AfficherMap(Map* m, SDL_Surface* screen, Snake* s);
int LibererMap(Map* m);

// Prototype de render du Snake
void AfficherSnake(Snake* snake, SDL_Surface* screen);

void afficherMenu(SDL_Surface* screen);
void afficherScore(Snake* s, SDL_Surface* screen);

void afficherLevelSelector(SDL_Surface* screen);
void afficherRegle(SDL_Surface* screen);

void afficherBestScore(SDL_Surface* screen);

#endif // RENDER_H_INCLUDED
