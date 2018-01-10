#include "utility.h"

void randomFruit(Map* m)
{
    int xAleat, yAleat;

    //Si le nombre de fruit est egal a 0
        //On gerenere une position aleatoire
        srand(time(NULL));
        xAleat = rand()%(40 - 1);
        yAleat = rand()%(20 - 1);

        //On incremente le nombre de fruit


        //On positionne la pomme dans la map
        /*if(m->schema[xAleat][yAleat] == VIDE){*/
            m->schema[xAleat][yAleat] = POMME;
                m->nbFruit++;
       /* else
        {
            randomFruit(m);
        }*/


}
