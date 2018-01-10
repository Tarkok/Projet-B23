#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <stdio.h>

#include "character.h"
#include "render.h"
#include "structures.h"
#include "time.h"

/**File storing all the variable, constant and math object needed*/
enum TILE_NAME{TETE, CORPS, QUEUE, MUR, VIDE, PIEGE, POMME};

int stop; // for the update function

void randomFruit(Map* m);


#endif // UTILITY_H_INCLUDED
