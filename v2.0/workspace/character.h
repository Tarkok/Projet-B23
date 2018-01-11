#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <SDL.h>

#include "structures.h"
#include "utility.h"


Snake* loadSnake();


void changeDirection(int orientation, Snake* snake);
void updatePosition(Snake* snake);
void eatFruit(Snake* snake, Map* m);

void checkTile(Snake* snake, Map* m, SDL_Surface* screen, Game* g);

void libererSnake(Snake* snake);

//Affiche le score, le stocke et retourne au menu
void mourir(Game* g);

#endif // CHARACTER_H_INCLUDED
