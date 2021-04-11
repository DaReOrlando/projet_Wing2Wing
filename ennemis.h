#ifndef _ENNEMIS_H_
#define _ENNEMIS_H_

#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>

struct PositionE //structure comprenant les coordonnées de l'ennemi
{
	int x;
	int y;
};

typedef struct ennemis ennemis;  //structure de l'ennemi
struct ennemis
{
	int vie;
	struct PositionE coord;
	bool active;
	struct ennemis *prevptr;
	struct ennemis *nextptr;
};

typedef struct listeEnnemis listeEnnemis; //structure qui gère la liste des ennemis
struct listeEnnemis
{
	
	int quantite;
	struct ennemis *starList;
	struct ennemis *endList;
	
};



typedef struct ennemis *ennemi; 
typedef struct listeEnnemis *listeEnnemi;
ennemi createEnnemi(int taille_x); //fonction qui crée un ennemi (initialise une structure ennemi)
listeEnnemi  initialListEnnemis(); //fonction qui innitialise la structure listeEnnemis
void insertionEnnemis(listeEnnemi es, ennemi q); //fonction qui permet d'ajouter un nouvel ennemi
void suppressionEnnemis(listeEnnemi es, bool test); //fonction qui supprime un ennemi
ennemi q;
listeEnnemi es;

#endif
