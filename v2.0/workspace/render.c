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
            if(strcmp(buf2, "dead")== 0)
            {
                carte->tiles[numTile].canKill = 1;
            }
        }

    }

}

void ErrorQuit(const char* error)
{
    puts(error);
    SDL_Quit();
    system("pause");
    exit(-1);
}

void loadMap_level(FILE* filePath, Map* carte)
{
    int i,j;
    fscanf(filePath, "%d %d", &carte->nbTilesHeightWorld, &carte->nbTilesHeightWorld);
    carte->plan = malloc(carte->nbTilesHeightWorld*sizeof(unsigned char));
    for(i=0; i < carte->nbTilesWidthWorld;i++)
    {
        carte->plan[i] = malloc(carte->nbTilesHeightWorld*sizeof(unsigned char));
    }
    for(j=0;j<carte->nbTilesHeightWorld;j++)
    {
        for(i=0; i < carte->nbTilesWidthWorld; i++)
        {
            int tmp;
            fscanf(filePath,"%d", &tmp);
            if(tmp>=carte->NB_TILE_WIDTH*carte->NB_TILE_HEIGHT)
            {
                ErrorQuit("level tile out of limits\n");
            }
            carte->plan[i][j] = tmp;
        }
    }
}

Map* loadMap(const char* level)
{
    FILE* F;
    Map* m;
    char buf[5000];
    F = fopen(level,"r"); //Ouverture du fichier en read only
    if(!F)
        ErrorQuit("can't find level file");
    fgets(buf, 5000, F);
    if(strstr(buf, "Tilemapping Snake") == 0)
        ErrorQuit("Baf files version\n");

    m = malloc(sizeof(Map));
    do
    {
        fgets(buf,5000,F);
        if (strstr(buf,"#tileset"))
            loadMapTileSet(F,m);
        if (strstr(buf,"#level"))
            loadMap_level(F,m);
    } while (strstr(buf,"#fin")==NULL);

    fclose(F);
    return m;
}

int drawMap(Map* carte, SDL_Surface* screen)
{
    int i,j;
    SDL_Rect Rect_dest;
    int nb_tiles;
    for(i = 0; i < carte->nbTilesWidthWorld;i++)
    {
        for(j=0;j<carte->nbTilesHeightWorld;j++)
        {
            Rect_dest.x = i * carte->TILE_WIDTH;
            Rect_dest.y = j * carte->TILE_HEIGHT;
            nb_tiles = carte->plan[i][j];
            SDL_BlitSurface(carte->tileset,&(carte->tiles[nb_tiles].R), screen, &Rect_dest);
        }
    }

    return 0;
}

int clearMap(Map* carte)
{
    int i;
    SDL_FreeSurface(carte->tileset);
    for(i = 0; i < carte->nbTilesHeightWorld;i++)
        free(carte->plan[i]);
    free(carte->plan);
    free(carte->tiles);
    free(carte);
    return 0;
}
