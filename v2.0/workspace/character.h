#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <SDL.h>

#include "structures.h"
#include "utility.h"


Snake* loadSnake();

// Capte les ordres de changement de direction
void changeDirection(int orientation, Snake* snake);

// Fait avancer le Snake
void updatePosition(Snake* snake);

// Snake mange les fruits
void eatFruit(Snake* snake, Map* m);

// Snake change de direction
void checkTile(Snake* snake, Map* m, SDL_Surface* screen, Game* g);

// Vide le Snake de la mémoire
void libererSnake(Snake* snake);

// Affiche le score, le stocke et retourne au menu
void mourir(Game* g);

#endif // CHARACTER_H_INCLUDED
