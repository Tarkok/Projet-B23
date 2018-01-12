#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <SDL_ttf.h>

#include "character.h"
#include "utility.h"
#include "render.h"
#include "structures.h"


int main ( int argc, char** argv ) // Main surchargé pour SDL
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
    // Init le snake
    Snake* snake ;

    snake = loadSnake();

    // Boucle principale
    //Creer le jeu et les etats de jeu
    Game* jeu;

    jeu->sceneEnCours = NULL;

    // Game main loop

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
                    // CONTROLES EN JEU
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        jeu->sceneEnCours = MENU;
                    }
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
                        if(jeu->sceneEnCours == SCORE)
                        {
                            jeu->sceneEnCours = MENU;
                        }
                        else if(jeu->sceneEnCours == MENU)
                        {
                            jeu->sceneEnCours = LEVEL_SELECTOR;
                        }
                    }

                    /** NAVIGATION DANS LES MENUS : CHOIX DU LEVEL */
                    if(event.key.keysym.sym == SDLK_1)
                    {
                        if(jeu->sceneEnCours == MENU)
                        {
                            jeu->sceneEnCours = LEVEL_SELECTOR;
                        }
                        else if(jeu->sceneEnCours == LEVEL_SELECTOR)
                        {
                            snake->orientation = 0;
                            snake->lengthQueue = 0;
                            snake->positionTete.x = 64;
                            snake->positionTete.y = 64;
                            beginTime = clock();
                            m = ChargerMap("txt/level_1_1.txt");
                            jeu->sceneEnCours = IN_GAME;
                        }

                    }
                    if(event.key.keysym.sym == SDLK_2)
                    {
                        if(jeu->sceneEnCours == MENU)
                        {
                            jeu->sceneEnCours = REGLE;
                        }
                        else if(jeu->sceneEnCours == LEVEL_SELECTOR)
                        {
                            snake->positionTete.x = 64;
                            snake->positionTete.y = 64;
                            snake->orientation = 0;
                            snake->lengthQueue = 0;
                            beginTime = clock();
                            m = ChargerMap("txt/level_2_1.txt");
                            jeu->sceneEnCours = IN_GAME;
                        }
                    }
                    if(event.key.keysym.sym == SDLK_3)
                    {
                        if(jeu->sceneEnCours == MENU)
                        {
                            jeu->sceneEnCours = SCORE_MENU;
                        }
                        else if(jeu->sceneEnCours == LEVEL_SELECTOR)
                        {
                            beginTime = clock();
                            snake->positionTete.x = 64;
                            snake->positionTete.y = 64;
                            snake->orientation = 0;
                            snake->lengthQueue = 0;
                            m = ChargerMap("txt/level_2_2.txt");
                            jeu->sceneEnCours = IN_GAME;
                        }
                    }
                    if(event.key.keysym.sym == SDLK_4)
                    {
                        if(jeu->sceneEnCours == LEVEL_SELECTOR)
                        {
                            beginTime = clock();
                            snake->positionTete.x = 64;
                            snake->positionTete.y = 64;
                            snake->orientation = 0;
                            snake->lengthQueue = 0;
                            m = ChargerMap("txt/level_2_3.txt");
                            jeu->sceneEnCours = IN_GAME;
                        }
                    }
                    if(event.key.keysym.sym == SDLK_5)
                    {
                        if(jeu->sceneEnCours == LEVEL_SELECTOR)
                        {
                            beginTime = clock();
                            snake->positionTete.x = 64;
                            snake->positionTete.y = 64;
                            snake->orientation = 0;
                            snake->lengthQueue = 0;
                            m = ChargerMap("txt/level_3_1.txt");
                            jeu->sceneEnCours = IN_GAME;
                        }
                    }
                    if(event.key.keysym.sym == SDLK_6)
                    {
                        if(jeu->sceneEnCours == LEVEL_SELECTOR)
                        {
                            beginTime = clock();
                            snake->positionTete.x = 64;
                            snake->positionTete.y = 64;
                            snake->orientation = 0;
                            snake->lengthQueue = 0;
                            m = ChargerMap("txt/level_3_2.txt");
                            jeu->sceneEnCours = IN_GAME;
                        }
                    }
                    if(event.key.keysym.sym == SDLK_7)
                    {
                        if(jeu->sceneEnCours == LEVEL_SELECTOR)
                        {
                            beginTime = clock();
                            snake->positionTete.x = 64;
                            snake->positionTete.y = 64;
                            snake->orientation = 0;
                            snake->lengthQueue = 0;
                            m = ChargerMap("txt/level_3_3.txt");
                            jeu->sceneEnCours = IN_GAME;
                        }
                    }
                    if(event.key.keysym.sym == SDLK_8)
                    {
                        if(jeu->sceneEnCours == LEVEL_SELECTOR)
                        {
                            beginTime = clock();
                            snake->positionTete.x = 64;
                            snake->positionTete.y = 64;
                            snake->orientation = 0;
                            snake->lengthQueue = 0;
                            m = ChargerMap("txt/level_3_3.txt");
                            jeu->sceneEnCours = IN_GAME;
                        }
                    }
                    break;
                }
            } // end switch
        } // end of message processing

        //ACTION SUR LES DIFFERENTS ETATS DE JEU
        if(jeu->sceneEnCours == MENU)
        {
            afficherMenu(screen);
        }
        if(jeu->sceneEnCours == IN_GAME)
        {
            play(m,snake,screen, jeu);
        }
        if(jeu->sceneEnCours == SCORE)
        {
            afficherScore(snake, screen);
        }
        if(jeu->sceneEnCours == LEVEL_SELECTOR)
        {
            afficherLevelSelector(screen);
        }
        if(jeu->sceneEnCours == REGLE)
        {
            afficherRegle(screen);
        }
        if(jeu->sceneEnCours == SCORE_MENU)
        {
            afficherBestScore(screen);
        }
    } // end main loop

    LibererMap(m);
    libererSnake(snake);

    // Tout est ok
    TTF_Quit();
    SDL_Quit();
    return 0;
}
