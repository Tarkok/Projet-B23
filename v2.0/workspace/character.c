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
}

void eatFruit(Snake* snake)
{
    snake->lengthQueue++;
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

    s->imgTete = LoadImage32("head.bmp");


    return s;
}

void checkTile(Snake* s, Map* m, SDL_Surface* screen)
{
    if(m->props[m->schema[s->positionX][s->positionY]].plein == 1)
    {
        // mourir(s, screen);
    }
}
