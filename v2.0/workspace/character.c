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
        snake->positionTete.y-=32;
        break;
    case 1:
        snake->positionTete.x-=32;
        break;
    case 2:
        snake->positionTete.x+=32;
        break;
    case 3:
        snake->positionTete.y+=32;
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
    s->positionTete.x = 3;
    s->positionTete.y = 3;

    s->lengthQueue = 0;

    s->imgTete = LoadImage32("tileset.bmp");


    return s;
}
