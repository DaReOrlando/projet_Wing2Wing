#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "load_map.h"
#include "joueur.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

joueur creation_joueur(int taille_x, int taille_y)
{
	joueur un;

	int x = 0, y = 0;

	for (int i = 0; i < taille_y; ++i)
	{
		for (int j = 0; j < taille_x; ++j)
		{
			if(*(*(map + i) + j) == '+')
			{
				x = j;
				y = i;

			}
		}
	}

	un = malloc(sizeof(joueur));
	un->vie = 3;
	un->degat=1;
	un->score=0;
	un->coord.x = x;
	un->coord.y = y;

	return un;
}



void gauche(joueur un)		//la fonction va vérifier si on peut se déplacer vers la gauche et le faire le cas échéant
{
	int x = 0;
	int y = 0;
	
	x = un->coord.x-1;
	y = un->coord.y;
	

	if (*(*(map + y) + x)!= '|')
	{
		un->coord.x = x;
	}

}

void droite(joueur un)		//la fonction va vérifier si on peut se déplacer vers la droite et le faire le cas échéant
{
	
	int x = 0;
	int y = 0;
	
	x = un->coord.x+1;
	y = un->coord.y;


	if (*(*(map + y) + x)!='|') 
	{
		un->coord.x = x;
	}

}



void haut(joueur un) 		//la fonction va vérifier si on peut se déplacer vers le haut et le faire le cas échéant
{
 
	int x = 0;
	int y = 0;
      
	x = un->coord.x;
	y = un->coord.y-1;


	if (*(*(map + y) + x)!='|')
	{
		un->coord.y = y;
	}     

}

void bas(joueur un)		//la fonction va vérifier si on peut se déplacer vers le bas et le faire le cas échéant
{
 
	int x = 0;
	int y = 0;

   	x = un->coord.x;
   	y = un->coord.y+1;
   
   	if (*(*(map + y) + x) !='|')
    {
		un->coord.y = y;
    }
}

