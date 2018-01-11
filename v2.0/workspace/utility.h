#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <stdio.h>

#include "character.h"
#include "render.h"
#include "structures.h"
#include "time.h"


/** Stock les variables et les constantes recquises
simplifie les appels*/
enum TILE_NAME{MUR, VIDE, PIEGE, POMME, POMME_BONUS, POMME_MALUS , POMME_GOLDEN};

void randomFruit(Map* m);

#endif // UTILITY_H_INCLUDED
