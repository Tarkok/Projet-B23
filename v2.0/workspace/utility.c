#include "utility.h"

void update(Snake* snake, SDL_Surface* screen)
{
    AfficherSnake(snake, screen);
    updatePosition(snake);

    SDL_Flip(screen);
    if(stop == 1)
    {
        update(snake, screen);

    }
}
