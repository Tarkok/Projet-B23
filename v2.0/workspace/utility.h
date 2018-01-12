#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <stdio.h>
#include <conio.h>

#include "character.h"
#include "render.h"
#include "structures.h"
#include "time.h"

/** Stock les variables et les constantes recquises
simplifie les appels*/

enum TILE_NAME{MUR, VIDE, PIEGE, POMME, POMME_BONUS, POMME_MALUS , POMME_GOLDEN};
enum GAME_SCENE{MENU, IN_GAME, LEVEL_SELECTOR, REGLE, SCORE};

int bestScore[3];

clock_t beginTime;
clock_t gameTime;

void play(Map* m, Snake* snake, SDL_Surface* s, Game* g);
void stockerScore(Snake* snake,int bestScore[3]);
void chargerBestScore(int bestScore[3]);

void randomFruit(Map* m);

#endif // UTILITY_H_INCLUDED
