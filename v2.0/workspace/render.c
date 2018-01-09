#include "render.h"

SDL_Surface* LoadImage(const char* filePath)
{
    SDL_Surface* image_result;
    SDL_Surface* image_ram = SDL_LoadBMP(filePath); //on charge l'image dans la ram

    if(image_ram == NULL)
    {
        printf("File %s can't be load\n", filePath);
        SDL_Quit();
        system("pause");
        exit(-1);
    }
    image_result = SDL_DisplayFormat(image_ram);
    SDL_FreeSurface(image_ram);

    return image_result;
}

void loadMapTileSet(FILE* filePath, Map* carte)
{
    int i,j,numTile;
    //On recupere le path de l'image dans le txt
    char buf[5000];//Petite zone memoire tampon
    char buf2[5000];
    fscanf(filePath,"%s",buf);
    //On charge l'image du tileset
    carte->tileset = LoadImage(filePath);

    //On calcule la taille d'un tile
    fscanf(filePath,"%d %d", &carte->NB_TILE_WIDTH, &carte->NB_TILE_HEIGHT);
    carte->TILE_WIDTH = carte->tileset->w / carte->NB_TILE_WIDTH;
    carte->TILE_HEIGHT = carte->tileset->h / carte->NB_TILE_HEIGHT;

    //On alloue l'espac memoire nessecaire pour stocker le tableau
    carte->tiles = malloc(carte->NB_TILE_WIDTH*carte->NB_TILE_HEIGHT*sizeof(Tile));

    for(j=0, numTile= 0; j < carte->NB_TILE_HEIGHT;j++)
    {
        for(i=0;i<carte->NB_TILE_WIDTH; i++, numTile++)
        {
            //configuration des rectangles pour les tailles
            carte->tiles[numTile].R.w = carte->TILE_WIDTH;
            carte->tiles[numTile].R.h = carte->TILE_HEIGHT;
            carte->tiles[numTile].R.x = i *  carte->TILE_WIDTH;
            carte->tiles[numTile].R.y = j *  carte->TILE_HEIGHT;

            //mortalite des tiles
            fscanf(filePath, "%s %s", buf, buf2);
            carte->tiles[numTile].canKill = 0;
            if(strcmp(buf2, "plein")== 0)
            {
                carte->tiles[numTile].canKill = 1;
            }
        }

    }


}
