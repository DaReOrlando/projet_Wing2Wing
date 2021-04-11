#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "load_map.h"
#include "ennemis.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>


listeEnnemi initialListEnnemis()
{
	listeEnnemi es = malloc(sizeof(listeEnnemis));
	if (es == NULL)
	{
		exit(EXIT_FAILURE);
	}
	es->starList = NULL;
	es->endList = NULL;
	es->quantite = 0;
	return es;
}

ennemi createEnnemi(int taille_x)
{
	ennemi new = malloc(sizeof(ennemis));
	srand(time(0));
	int x = (rand() % (taille_x-2)+1);
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	} 
	new->vie = 1;
	new->coord.x = x;
	new->coord.y = 5;
	new->nextptr = NULL;
	new->prevptr = NULL;
	new->active = true;
	return new;
}

void insertionEnnemis(listeEnnemi es, ennemi base)
{
	ennemi new = malloc(sizeof(ennemis));
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new = base;
	if (es->starList == NULL || es->endList == NULL)
	{
		es->endList= new;
		es->starList = new;
	}
	else
	{
		new->nextptr = es->starList;
		es->starList->prevptr = new;
		es->starList = new;
	}
	es->quantite += 1;
}

void suppressionEnnemis(listeEnnemi es, bool test)
{
	test = false;
	if (es->starList != NULL)
	{
		ennemi base = malloc(sizeof(ennemis));
		if (base == NULL)
		{
			exit(EXIT_FAILURE);
		}
		base = es->starList;
		while (base != NULL)
		{
			if (base->active == test)
			{
				ennemi deleate = malloc(sizeof(ennemis));
				deleate = base;
				base = base->nextptr;
				if (es->starList == deleate && es->endList == deleate)
				{
					es->starList = NULL;
					es->endList = NULL;
				}
				else if (es->starList != deleate && es->endList == deleate)
				{
					es->endList = deleate->prevptr;
					es->endList->nextptr = NULL;
				}
				else if (es->starList == deleate && es->endList != deleate)
				{
					es->starList  = deleate->nextptr;
					es->starList->prevptr = NULL;
				}
				else
				{
					deleate->nextptr->prevptr = deleate->prevptr;
					deleate->prevptr->nextptr = deleate->nextptr;
				}
				free(deleate);
				es->quantite--;
			}
			else
			{
				base = base->nextptr;
			}
		}
	}
}
