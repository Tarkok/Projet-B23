#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "character.h"
#include "utility.h"
#include "render.h"

int main ( int argc, char** argv )
{
    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }
    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(1280, 640, 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF); //Pour tile 32 px 40 * 20
    SDL_WM_SetCaption("Snake !", NULL);

    //Create the map
    Map *m;
    m = ChargerMap("level_1_1.txt");

    AfficherMap(m,screen);
    SDL_Flip(screen);
    // program main loop
    int done = 0;
    while (done != 1)
    {
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
                    if(event.key.keysym.sym == SDLK_q)
                    {
                        //move(snake, direction);
                    }
                    break;
                }
            } // end switch
        } // end of message processing

    } // end main loop

    LibererMap(m);

    // all is well ;)
    SDL_Quit();
    printf("Exited cleanly\n");
    return 0;
}
