#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "mouv.h"

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *asset = NULL;
    SDL_Rect xy;
    xy.x=200;
    xy.y=200;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(1280, 640, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Snake v2.0", NULL);
    asset = SDL_LoadBMP("assets/asset.bmp");

    SDL_BlitSurface(asset, NULL, ecran, &xy);
    SDL_Flip(ecran);

    myPause();

    SDL_FreeSurface(asset);
    SDL_Quit();

    return 0;
}
