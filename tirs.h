#ifndef _TIRS_H_
#define _TIRS_H_

#include <stdbool.h>

#include "joueur.h"


struct positionT //structure position des tirs
{
	int x;
	int y;
};
typedef struct tirs tirs; //structure de tir
struct tirs
{
	struct positionT coord;
	bool active;
	struct tirs *prevptr;
	struct tirs *nextptr;
};

typedef struct listeTirs listeTirs; //structure reprennant l'ensemble des tirs
struct listeTirs
{
	
	int quantite;
	struct tirs *starList;
	struct tirs *endList;
	
};



typedef struct tirs *tirsP; 
typedef struct listeTirs *listetirsP;
tirsP createTirs(joueur un); //fonction qui initialise un tir
listetirsP  initialListeTirs(); //fonction qui initialise la liste des tirs
void insertionTirs(listetirsP t, tirsP base); //fonction qui permet d'ajouter un tir
void suppressionTirs(listetirsP t, bool test); //fonction qui permet de supprimer un tir
void tirer(joueur un, listetirsP t); //fonction qui reprend les fonctions createTirs et insertionTirs et qui permet au joueur de tirer
tirsP r;
listetirsP t;

#endif
