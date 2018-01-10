#include "utility.h"

void randomFruit(Map* m)
{
    int xAleat, yAleat;

    //Si le nombre de fruit est egal a 0
        //On gerenere une position aleatoire
        srand(time(NULL));
        xAleat = rand()%(40 - 1);
        yAleat = rand()%(20 -1);

        //On incremente le nombre de fruit
        m->nbFruit++;

        m->schema[xAleat][yAleat] = 6;
}
