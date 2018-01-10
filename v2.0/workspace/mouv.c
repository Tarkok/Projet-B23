#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "mouv.h"

void myPause()
{
    int continuer = 1;
    SDL_Event event;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
