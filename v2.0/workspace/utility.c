#include "utility.h"

void randomFruit(Map* m)
{
    int xAleat, yAleat;

    //Si le nombre de fruit est egal a 0
        //On gerenere une position aleatoire
        srand(time(NULL));
        xAleat = rand()%(40 - 2) + 1;
        yAleat = rand()%(20 - 2) + 1;

        //On incremente le nombre de fruit

        int objetAleat;
        objetAleat = rand()%100;
        if(objetAleat >= 0 && objetAleat <= 70)
        {
                m->schema[xAleat][yAleat] = POMME;
                m->nbFruit++;
        }
        else
        {
            if(objetAleat > 60 && objetAleat <= 85)
            {
                m->schema[xAleat][yAleat] = POMME_MALUS;
                m->nbFruit++;
            }
            else if(objetAleat > 75 && objetAleat <= 95)
            {
                m->schema[xAleat][yAleat] = POMME_BONUS;
                m->nbFruit++;
            }
            else if(objetAleat > 95 && objetAleat <= 100)
            {
                m->schema[xAleat][yAleat] = POMME_GOLDEN;
                m->nbFruit++;
            }

        }
}

void changerScene(Game* g, int Etat)
{
    int indice;
    //On cherche  notre Etat dans le tableau
    for(int i = 0; i < 5; i++)
    {
        if(g->etatJeu[i] == Etat)
        {
            indice = i;
        }
    }

    g->etatJeu[indice] = g->etatJeu[0];
    g->etatJeu[0] = Etat;

}

void play(Map* m, Snake* snake, SDL_Surface* screen)
{

            AfficherMap(m,screen);
            AfficherSnake(snake, screen);

            updatePosition(snake);

            checkTile(snake, m, screen);

            SDL_Flip(screen);

            SDL_Delay(m->vitesse);
}
