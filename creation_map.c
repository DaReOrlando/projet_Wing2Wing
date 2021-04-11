#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>


#include "load_map.h"
#include "creation_map.h"
#include "jeu.h"

void drawSky() //fonction qui crée le ciel
{
        glBegin(GL_POLYGON); 
            glColor3f(0.3,0.8,1);
	
            glVertex3f(taille_carre, 30*taille_carre, 0);
            glVertex3f(taille_carre, taille_carre, 0);
            glVertex3f(30*taille_carre, 0, 0);
            glVertex3f(30*taille_carre, 30*taille_carre, 0);
        glEnd();
}

void creation_murs(int taille_x, int taille_y)
{
	int i = 0, j = 0;
	for(i = 0; i < (taille_y); i++)
	{
		for(j = 0; j < (taille_x); j++)
		{
			drawSky();
			if(*(*(map + i) + j) == '|')
			{
				glColor3f(1.0f,1.0f,1.0f);
				glMatrixMode(GL_MODELVIEW);
				
			    	glLoadIdentity();
				glTranslatef(j*taille_carre, i*taille_carre,0.0f);
				
				
				glBegin(GL_QUADS);
				glColor3f(1.0,1.0,1.0);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(taille_carre, 0.0f, 0.0f);
				glVertex3f(taille_carre,taille_carre, 0.0f);
				glVertex3f(0.0f,taille_carre, 0.0f);

				glEnd();	
			}

			
		}
	}

}
void afficher_joueur(joueur un)
{
	int i, j;
	i = un->coord.x;
	j = un->coord.y;
	
	
	glColor3f(0.0f,1.0f,0.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(i*taille_carre,j*taille_carre,0.0f);

	glBegin(GL_QUADS);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(taille_carre, 0.0f, 0.0f);
	glVertex3f(taille_carre,taille_carre, 0.0f);
	glVertex3f(0.0f,taille_carre, 0.0f);

	glEnd();
}

void afficher_ennemi(ennemi e)
{
	int i, j;
	i = e->coord.x;
	j = e->coord.y;
	
	
	glColor3f(1.0f,0.0f,0.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(i*taille_carre,j*taille_carre,0.0f);

	glBegin(GL_QUADS);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(taille_carre, 0.0f, 0.0f);
	glVertex3f(taille_carre,taille_carre, 0.0f);
	glVertex3f(0.0f,taille_carre, 0.0f);

	glEnd();
}

void afficherTirsAllie(tirsP p)
{
	int i, j;
	i = p->coord.x;
	j = p->coord.y;
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef((i*Shoot_size)+5,j*Shoot_size,0.0f);
	glBegin(GL_QUADS);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(Shoot_size,0.0f,0.0f);
	glVertex3f(Shoot_size,Shoot_size,0.0f);
	glVertex3f(0.0f,Shoot_size,0.0f);
	glEnd();
}

void afficherTousEnnemis(listeEnnemi es)
{	
	ennemi first = malloc(sizeof(ennemis));
	ennemi next = malloc(sizeof(ennemis));
	first = es->starList;
	next = es->starList->nextptr;
	if (es->starList != NULL || es->endList != NULL)
	{
		afficher_ennemi(first);
		if (es->starList->nextptr != NULL)
		{
			afficher_ennemi(next);
			while (next->nextptr != NULL)
			{
				next = next->nextptr;
				afficher_ennemi(next);
			}
		}
	}
}

void afficherTousTirsAllie(listetirsP t)
{
	tirsP first = malloc(sizeof(tirs));
	tirsP next = malloc(sizeof(tirs));
	first = t->starList;
	if (t->starList != NULL && t->starList->nextptr != NULL)
	{
	next = t->starList->nextptr;
	}
	if (t->starList != NULL || t->endList != NULL)
	{
		afficherTirsAllie(first);
		if (t->starList->nextptr != NULL)
		{
			afficherTirsAllie(next);
			while (next->nextptr != NULL)
			{
				next = next->nextptr;
				afficherTirsAllie(next);
			}
		}
	}
}

void afficherScore(joueur un, int x, int y, void *font)
{

    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    glRasterPos2f(x, y); //750 - 575
    
    char *s=transformationScore(un);
    while(*s)
    {
        glutBitmapCharacter(font, *s);
        s++;
    }

}

void afficherVie(joueur un)
{

	
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    glRasterPos2f(25, 575); 
    
    char *s=transformationVie(un);
    while(*s)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *s);
        s++;
    }

}

void afficherGameOver(joueur un, int x, int y, void *font)
{
	glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    glRasterPos2f(x, y); 
    
    char *s="GAME OVER";
    while(*s)
    {
        glutBitmapCharacter(font, *s);
        s++;
    }

    afficherScore(un, x, y+20, font);
}
