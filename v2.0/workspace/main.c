#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

#include "character.h"
#include "utility.h"
#include "render.h"
#include "structures.h"


int main ( int argc, char** argv )
{
    // On init la video SDL
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }
    // Icone du programme
    SDL_WM_SetIcon(SDL_LoadBMP("media/assets/ico.bmp"), NULL);

    // Init une fenetre SDL
    SDL_Surface* screen = SDL_SetVideoMode(1280, 640, 16, SDL_HWSURFACE|SDL_DOUBLEBUF); //Pour tile 32 px 40 * 20
    SDL_WM_SetCaption("Snake v2.0", NULL);

    // Init la map
    Map *m;
    m = ChargerMap("level_1_1.txt");

    // Init le snake
    Snake* snake = loadSnake();

    // Boucle principale

    int done = 0;
    while (done != 1)
    {
        updatePosition(snake);
        checkTile(snake, m, screen);
        AfficherMap(m,screen);
        AfficherSnake(snake, screen);
        SDL_Flip(screen);
        SDL_Delay(m->vitesse);

        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
            // exit if the window is closed
            case SDL_QUIT:
                done = 1;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = 1;
                    if(event.key.keysym.sym == SDLK_s)
                    {
                        changeDirection(0, snake);
                    }
                    if(event.key.keysym.sym == SDLK_a)
                    {
                        changeDirection(1, snake);
                    }
                    if(event.key.keysym.sym == SDLK_d)
                    {
                        changeDirection(2, snake);
                    }
                    if(event.key.keysym.sym == SDLK_w)
                    {
                        changeDirection(3, snake);
                    }
                    break;
                }
            } // end switch
        } // end of message processing
    } // end main loop

    LibererMap(m);

    // all is well ;)
    SDL_Quit();
    return 0;
}
