#include <stdio.h>
#include <conio.h>
#include "outilMath.h"
#include "map.h"
#include "character.h"
#include "gameManager.h"


int main()
{
	int i, j;
	char input;
	Character Snake;
	Snake.positionTete.x = 2;
	Snake.positionTete.y = 2;
	Map carte;

	do
	{
		input = getch();
		manageInput(input, Snake);
		for (i = 0; i < 45; i++)
		{
			for (j = 0; j < 20; j++)
			{
				printf("%c",carte.carte[i][j]);
			}
			printf("\n");
		}

	} while (input != 'e');
	

	return 0;
}