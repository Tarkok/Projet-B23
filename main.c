#include <stdio.h>
#include <stdlib.h>

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

void load(const char* nomFichier, int carte[][HEIGHT])
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

void draw(int carte[][HEIGHT])
{
      for(int i = 0; i < HEIGHT; i++)
        {
            for(int j = 0; j < WIDTH; j++)
            {
                printf("%c",carte[j][i]);
            }
        }
        printf("\n");

        draw(*carte);
}

int main()
{
    int carte[WIDTH][HEIGHT];
    /** a)Deplacement manuel du snake*/
    load("level/level_1_2.txt", *carte);
    draw(*carte);



    return 0;
}
