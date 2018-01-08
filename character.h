#pragma once
#include "outilMath.h"

typedef struct {

	Point2D positionTete; // Position de la tete du serpent
	int length;			// Taille de la queue du serpent (sans la tete)
	int peutTraverser; //  Booléen, indique si l'ont peut traverser les murs

}Character;
