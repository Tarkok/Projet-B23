#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <SDL.h>

#include "structures.h"


Snake* loadSnake();


void changeDirection(int orientation, Snake* snake);
void updatePosition(Snake* snake);
void eatFruit(Snake* snake);

void libererSnake(Snake* snake);

#endif // CHARACTER_H_INCLUDED
