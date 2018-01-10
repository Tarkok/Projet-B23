#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <stdio.h>

#include "character.h"
#include "render.h"
#include "structures.h"

/**File storing all the variable, constant and math object needed*/
int stop; // for the update function


 void update(Snake* snake, SDL_Surface* screen);



#endif // UTILITY_H_INCLUDED
