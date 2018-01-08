#pragma once
#include "character.h"
#include "outilMath.h"

typedef struct {

	Point2D pos; //Position d'un objet
	int canKill; //Booléen 0 = mur, 1 = peutTue = piege

}Placable;

typedef struct {

	unsigned int width = 45;
	unsigned int height = 20;
	unsigned int carte[45][20];

	Character Snake;


}Map;
