#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

/**File storing all the variable, constant and math object needed*/

/*Tile et ses propriétés*/
typedef struct
{
    SDL_Rect R;
    int canKill; //Booleen : 0 non mortel, 1 : mortel
}Tile;

/*Carte d'un niveau*/
typedef struct{
    int TILE_WIDTH, TILE_HEIGHT; //Pour position en px
    int NB_TILE_WIDTH, NB_TILE_HEIGHT;//Pour position en coordonnées
    SDL_Surface* tileset;//Pointeur vers le tileset
    Tile* tiles; //Tableau contenant chaque type de tile
    unsigned char** plan; //Matrice pour contenir le plan du niveau
} Map;

typedef struct{
    int x;
    int y;
}Point2D;



#endif // UTILITY_H_INCLUDED
