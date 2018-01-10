#include "character.h"

void changeDirection(int orientation, Snake* snake)
{
    snake->orientation = orientation;
}

void updatePosition(Snake* snake)
{
    switch(snake->orientation)
    {
    case 0:
        snake->positionTete.y+=32;
        break;
    case 1:
        snake->positionTete.x-=32;
        break;
    case 2:
        snake->positionTete.x+=32;
        break;
    case 3:
        snake->positionTete.y-=32;
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
    s->positionTete.x = 64;
    s->positionTete.y = 64;

    s->positionX = s->positionTete.x / 32;
    s->positionY = s->positionTete.y / 32;

    s->orientation = 0;

    s->lengthQueue = 0;

    s->imgTete = LoadImage32("media/assets/h1.bmp");


    return s;
}


void checkTile(Snake* s, Map* m, SDL_Surface* screen)
{
    //Si snake cogne un mur
    if(m->props[m->schema[s->positionX][s->positionY]].type == PIEGE || m->props[m->schema[s->positionX][s->positionY]].type == MUR)
    {
        //mourir(s, screen);
        s->positionTete.x = 64;
        s->positionTete.y = 64;
    }

    //Si snake cogne un fruit
    if(m->props[m->schema[s->positionX][s->positionY]].type == POMME || m->props[m->schema[s->positionX][s->positionY]].type == POMME_BONUS ||
       m->props[m->schema[s->positionX][s->positionY]].type == POMME_GOLDEN ||m->props[m->schema[s->positionX][s->positionY]].type == POMME_MALUS)
    {
        eatFruit(s, m);
    }
}

void eatFruit(Snake* snake, Map* m)
{
    snake->lengthQueue++;
    m->nbFruit--;
    m->schema[snake->positionX][snake->positionY] = VIDE;
    randomFruit(m);
}
