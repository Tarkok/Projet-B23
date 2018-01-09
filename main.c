#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "variable.h"
#include "utility.h"

struct Snake{
    Point2D posTete;
    int longeurQueue;
    int canCrossWall;
    int estVivant;

    Point2D posQueue[WIDTH * HEIGHT];
};
typedef struct Snake Snake;

void mourrir(Snake snake)
{
    snake.estVivant = 1;
    system("cls");
    printf("YOU LOSE\n SCORE : &d\n", snake.longeurQueue);
    printf("PRESS M TO GO BACK TO THE MENU");
}



int collision(Snake snake, int carte[][HEIGHT])
{
    /*Collision */
    if(carte[snake.posTete.x][snake.posTete.y] != ' ')
    {
        /*Collision avec un fruit = MANGE*/
        if(carte[snake.posTete.x][snake.posTete.y] == 'f')
        {
            /**/
            snake.longeurQueue++;
            // snake.posQueue[longueurQueue] = ;
        }
        /*Collision Mortelle*/
        else if((snake.canCrossWall == 0 && carte[snake.posTete.x][snake.posTete.y] == '#') || carte[snake.posTete.x][snake.posTete.y] == 'X')
        {
            mourrir(snake);
        }
        /*Collision Non Mortelle*/


    }
}

void apparaitreObjet(int carte[][HEIGHT])
{
    Point2D positionAleat;

    //Si le nombre de fruit est egal a 0
    if(nbFruit == 0)
    {
        //On gerenere une position aleatoire
        srand(time(NULL));
        positionAleat.x = rand()%(WIDTH - 1)+1;
        positionAleat.y = rand()%(HEIGHT -1)+1;

        //On incremente le nombre de fruit
        nbFruit++;

        //On stocke la postion dans la carte
        carte[positionAleat.x][positionAleat.y] = 'f';
    }

}


void update(Snake snake, int carte[][HEIGHT])
{
    //Gerer l'appel des fonction a chaque frame
    //Verifie les events
    apparaitreObjet();
    draw(*carte);
    attendre(0.25);

    if(snake.estVivant == 0)
    {
        update(*carte); //recursivite si snake est en vie
    }

}

void load(const char* nomFichier, int carte[][HEIGHT])
{
   FILE* fichier = fopen(nomFichier, "r");

   if(fichier != NULL)
   {
      for(int i = 0; i < HEIGHT; i++)
        {
            for(int j = 0; j < WIDTH; j++)
            {
                carte[j][i] = getc(fichier);;
            }

        }

        fclose(fichier);
   }
   else
   {
       printf("Impossible de charger le niveau\n");
   }
}

void draw(int carte[][HEIGHT])
{
    system("cls");
      for(int i = 0; i < HEIGHT; i++)
        {
            for(int j = 0; j < WIDTH; j++)
            {
                printf("%c", carte[j][i]);
            }
            printf("\n");
        }

}

int main()
{
    Snake snake;
    snake.canCrossWall = 0;
    snake.estVivant = 1;
    snake.longeurQueue = 1;
    snake.posTete.x = 3;
    snake.posTete.y = 3;
    /*snake.posQueue[0].x = 3;
    snake.posQueue[0].y = 2;*/

    long int carte[WIDTH][HEIGHT];
    /** a)Deplacement manuel du snake*/
    load("level/level_1_1.txt", *carte);
    update(*carte);




    return 0;
}
