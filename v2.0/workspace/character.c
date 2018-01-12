#include "character.h"

void changeDirection(int orientation, Snake* snake)
{
    snake->orientation = orientation;
}

void updatePosition(Snake* snake)
{
    //Change position du corps
    int i;
    for(i = snake->lengthQueue; i >= 1; i--)
    {
        snake->positionCorps[i] = snake->positionCorps[i-1];
    }
    snake->positionCorps[0] = snake->positionTete;


    //Change position de la tete
    switch(snake->orientation)
    {
    case 0:
        snake->positionTete.y+=32;
        snake->teteAff = snake->imgTete[3];
        snake->queueAff = snake->imgQueue[3];
        break;
    case 1:
        snake->positionTete.x-=32;
        if(snake->positionTete.x < 0)
        {
            snake->positionTete.x = 0; //Bug du négatif
        }
        snake->teteAff = snake->imgTete[0];
        snake->queueAff = snake->imgQueue[0];
        break;
    case 2:
        snake->positionTete.x+=32;
        snake->teteAff = snake->imgTete[2];
        snake->queueAff = snake->imgQueue[2];
        break;
    case 3:
        snake->positionTete.y-=32;
        if(snake->positionTete.y < 0)
        {
                    snake->positionTete.y = 0;
        }
        snake->teteAff = snake->imgTete[1];
        snake->queueAff = snake->imgQueue[1]; //BUG
        break;
    default:
        break;
    }
    snake->positionX = snake->positionTete.x / 32;
    snake->positionY = snake->positionTete.y / 32;

}

Snake* loadSnake()
{
    Snake* s;
    s->positionX = s->positionTete.x / 32;
    s->positionY = s->positionTete.y / 32;

    s->orientation = 0;
    s->lengthQueue = 0;

    // Creation dynamique du tableau pour les differentes tete
    s->imgTete = (SDL_Surface**)malloc(sizeof(SDL_Surface**)*8);
    s->imgTete[0] = LoadImage32("media/assets/h1.bmp");
    s->imgTete[1] = LoadImage32("media/assets/h2.bmp");
    s->imgTete[2] = LoadImage32("media/assets/h3.bmp");
    s->imgTete[3] = LoadImage32("media/assets/h4.bmp");

    // Creation dynamique du tableau pour les differentes queue
    s->imgQueue = (SDL_Surface**)malloc(sizeof(SDL_Surface**)*8);
    s->imgQueue[0] = LoadImage32("media/assets/q1.bmp");
    s->imgQueue[1] = LoadImage32("media/assets/q2.bmp");
    s->imgQueue[2] = LoadImage32("media/assets/q3.bmp");
    s->imgQueue[3] = LoadImage32("media/assets/q4.bmp");

    // Chargement de l'image du corps
    s->imgCorps = LoadImage32("media/assets/b1.bmp");

    return s;
}

void checkTile(Snake* s, Map* m, SDL_Surface* screen, Game* g)
{
    // Si snake cogne un mur
    if( (m->props[m->schema[s->positionX][s->positionY]].type == PIEGE) ||
        (m->props[m->schema[s->positionX][s->positionY]].type == MUR && m->crossWall == 0) )  //Meurt
    {
            g->sceneEnCours = SCORE; //Menu Score
    }

    // Si le crosswall est active
    if(m->props[m->schema[s->positionX][s->positionY]].type == MUR && m->crossWall == 1)
    {
        // On le teleporte de l'autre cote en fonction de sa position
        switch(s->positionTete.x)
        {
        case 1280-32:
            s->positionTete.x = 32;
            break;
        case 0:
            s->positionTete.x = 1280-32;
            break;
        default:
            break;
        }

        switch(s->positionTete.y)
        {
        case 640-32:
            s->positionTete.y = 32;
            break;
        case 0:
            s->positionTete.y = 640-64;
            break;
        default:
            break;
        }
    }

    int i;
    for(i = 0; i < s->lengthQueue; i++)
    {
        if(s->positionTete.x == s->positionCorps[i].x && s->positionTete.y == s->positionCorps[i].y)
        {
             g->sceneEnCours = SCORE; // Meurt, écran des scores
        }
    }

    // Si snake cogne un fruit
    if(m->props[m->schema[s->positionX][s->positionY]].type == POMME ||
       m->props[m->schema[s->positionX][s->positionY]].type == POMME_BONUS ||
       m->props[m->schema[s->positionX][s->positionY]].type == POMME_GOLDEN ||
       m->props[m->schema[s->positionX][s->positionY]].type == POMME_MALUS)
    {
        eatFruit(s, m);
    }
}

void eatFruit(Snake* snake, Map* m)
{
    if(m->props[m->schema[snake->positionX][snake->positionY]].type == POMME)
        snake->lengthQueue++;
    else if(m->props[m->schema[snake->positionX][snake->positionY]].type == POMME_BONUS)
        snake->lengthQueue = snake->lengthQueue + 2;
    else if(m->props[m->schema[snake->positionX][snake->positionY]].type == POMME_GOLDEN)
        snake->lengthQueue = snake->lengthQueue + 3;
    else if(m->props[m->schema[snake->positionX][snake->positionY]].type == POMME_MALUS)
    {
        if(snake->lengthQueue > 0)
            snake->lengthQueue--;
    }

    m->schema[snake->positionX][snake->positionY] = VIDE;
    randomFruit(m);
}

void libererSnake(Snake* snake)
{
    SDL_FreeSurface(snake->imgCorps);
    int i;
    for(i = 0; i < 4; i++)
    {
        SDL_FreeSurface(snake->imgQueue[i]);
        SDL_FreeSurface(snake->imgTete[i]);
    }
    SDL_FreeSurface(snake->teteAff);
    SDL_FreeSurface(snake->queueAff);
    free(snake);
}
