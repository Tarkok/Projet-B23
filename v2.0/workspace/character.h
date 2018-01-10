#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <SDL.h>

#include "structures.h"


Snake* loadSnake();


void changeDirection(int orientation, Snake* snake);
void updatePosition(Snake* snake);
void eatFruit(Snake* snake);

void checkTile(Snake* snake, Map* m, SDL_Surface* screen);

void libererSnake(Snake* snake);

void mourir();

#endif // CHARACTER_H_INCLUDED
