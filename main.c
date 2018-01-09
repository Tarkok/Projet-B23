#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaration des constantes & variables
const int WIDTH = 25;
const HEIGHT = 15;


struct Point2D{
    int x;
    int y;
};
typedef struct Point2D Point2D;

struct Snake{
    Point2D posTete;
    Point2D posQueue[];
};
typedef struct Snake Snake;

void attendre(float temps)
{
    clock_t terminer=clock()+(temps*CLOCKS_PER_SEC); // On calcule le moment où l'attente devra s'arrêter

    while(clock()<terminer);
}

void update(int carte[][HEIGHT])
{
    //Gerer l'appel des fonction a chaque frame
    //Verifie les events
    draw(*carte);
    attendre(0.25);
    update(*carte); //recursivite
}

void load(const char* nomFichier, char carte[][HEIGHT])
{
   FILE* fichier = fopen(nomFichier, "r");

   if(fichier != NULL)
   {
      for(int i = 0; i < HEIGHT; i++)
        {
            for(int j = 0; j < WIDTH; j++)
            {
                carte[j][i] = getc(fichier);
            }
        }

        fclose(fichier);
   }
   else
   {
       printf("Impossible de charger le niveau\n");
   }
}

void draw(char carte[][HEIGHT])
{
    system("cls");
      for(int i = 0; i < HEIGHT; i++)
        {
            for(int j = 0; j < WIDTH; j++)
            {
                if(carte[j][i] == '1')
                {
                    printf("#");
                }
                if(carte[j][i] == ' ')
                {
                    printf(" ");
                }
                if(carte[j][i] == '2')
                {
                    printf("#");
                }
            }
             printf("\n");
        }

}

int main()
{
    char carte[WIDTH][HEIGHT];
    /** a)Deplacement manuel du snake*/
    load("level/level_1_1.txt", *carte);
    update(*carte);



    return 0;
}
