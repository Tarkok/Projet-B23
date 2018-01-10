#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "character.h"
#include "utility".h
#include "render.h"

int main ( int argc, char** argv )
{
    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(1280, 640, 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF); //Pour tile 32 px 40 * 20
    SDL_WM_SetCaption("Snake !", NULL);

    if ( !screen )
    {
        printf("Unable to set 1280x640 video: %s\n", SDL_GetError());
        return 1;
    }

    //Create the map
    Map m;
    m -> loadMap("level/level_1_1");

    // program main loop
    bool done = false;
    while (!done)
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
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        // clear screen
        //SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        if(drawMap(m, screen) != 0)
        {
            printf("Cannot load map\n");
        }


        // DRAWING ENDS HERE

        // finally, update the screen

        SDL_Flip(screen);

    } // end main loop


        if(clearMap(m) != 0)
        {
            printf("Cannot clear map\n");
        }

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
