#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <GL/freeglut.h>

#include "load_map.h"
#include "creation_map.h"

bool UP = false;
bool LEFT = false;
bool RIGHT = false;
bool DOWN = false;
bool SHOOT = false;
bool CHECKCOLLISION = false;


void Keyboard(unsigned char key, int x, int y)  
{
	switch(key)
	{
		case 27:
			exit(0);

		case'z':
			UP = true;
			break;

		case'q':
			LEFT = true;
			break;

		case'd':
			RIGHT = true;
			break;

		case's':
			DOWN = true;
			break;

		case 32:
			SHOOT = true;
			break;	
	}	
}

char *transformationScore(joueur un)
{
	
	static char textScore[50];
	int score = un->score;

	sprintf(textScore, "Score : %i", score);
	return textScore;

}

char *transformationVie(joueur un)
{
	
	static char textVie[50];
	int vie = un->vie;

	sprintf(textVie, "Vies : %i", vie);
	return textVie;

}

void jeu(int taille_x, int taille_y, joueur un, listeEnnemi es, listetirsP t, bool pauseVie)
{


	creation_murs(taille_x, taille_y);	
	afficher_joueur(un);		
	


	
	if (es->starList != NULL || es->endList != NULL)
	{
		afficherTousEnnemis(es);
	}	

	if (t->starList != NULL || t->endList != NULL)
	{
		afficherTousTirsAllie(t);
	}
	afficherVie(un);

	afficherScore(un, 750, 575, GLUT_BITMAP_TIMES_ROMAN_24);

	if(pauseVie==true)
	{
		afficherGameOver(un, 375, 300, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(pauseVie==false)
	{
		glutKeyboardFunc(Keyboard);		//fonction de glut gérant le clavier
	
		if (LEFT == true)
		{
			
			gauche(un);		//va se déplacer vers la gauche si on appuie sur q
			
			LEFT = false;
			
		}
		if (RIGHT == true)
		{
			
			droite(un);		//va se déplacer vers la droite si on apppuie sur d
			RIGHT = false;
			
		}
		if (UP == true)
		{
			haut(un);		//va se déplacer vers le haut si on apppuie sur z
			UP = false;
			
		}
		
		if (DOWN == true)
		{
			
    	    bas(un);		//va se déplacer vers le bas si on apppuie sur s
			DOWN = false;
			
		}
	
		if (SHOOT == true)
		{
			tirer(un, t);	//va créer un nouveau tir
			SHOOT=false;
		}

		glutPostRedisplay();
	}
}


void checkCollision (ennemi q, tirsP r, joueur un)
{	
	
	int rx, ry, ex, ey;

	rx = ((r->coord.x) * Shoot_size) +5;
	ry = (r->coord.y) * Shoot_size;
	ex = q->coord.x * taille_carre;
	ey = q->coord.y * taille_carre;
	

	if(rx + Shoot_size > ex && rx < ex + taille_carre && ry + Shoot_size > ey && ry < ey + taille_carre)
	{
		CHECKCOLLISION = true;
	}


	if (CHECKCOLLISION)
	{
		q->active = false;
		r->active = false;
		un->score++;
		
		CHECKCOLLISION = false;
	}
} 



