#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "character.h"
#include "utility.h"
#include "render.h"
#include "structures.h"


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

    //Create the snake
    Snake* snake = loadSnake();

    //Creer le jeu et les etats de jeu
    Game* jeu;
    GameScene* menu;
    //menu = ChargerGameScene();
    jeu->etatJeu[0] = menu;
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
                    if(event.key.keysym.sym == SDLK_SPACE)
                    {
                        changerScene(jeu, IN_GAME);
                    }
                    break;
                }
            } // end switch

        } // end of message processing
        if(jeu->etatJeu[0] == IN_GAME)
        {
            play(m,snake,screen);
        }


    } // end main loop

    LibererMap(m);

    // all is well ;)
    SDL_Quit();
    printf("Exited cleanly\n");
    return 0;
}
