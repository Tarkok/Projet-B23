#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <stdio.h>
#include <conio.h>

#include "character.h"
#include "render.h"
#include "structures.h"
#include "time.h"


/**File storing all the variable, constant and math object needed*/
enum TILE_NAME{MUR, VIDE, PIEGE, POMME, POMME_BONUS, POMME_MALUS , POMME_GOLDEN};
enum GAME_SCENE{MENU, IN_GAME, LEVEL_SELECTOR, REGLE, SCORE};

void play(Map* m, Snake* snake, SDL_Surface* s, Game* g);

int stop; // for the update function

void randomFruit(Map* m);



#endif // UTILITY_H_INCLUDED
