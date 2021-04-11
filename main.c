#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>

#include "load_map.h"
#include "creation_map.h"
#include "jeu.h"
#include "joueur.h"
#include "ennemis.h"
#include "tirs.h"

int taille_x;
int taille_y;
joueur un;

bool test = false;
bool pauseVie = false;

void updateVie(int valeur) //fonction qui vérifie que le joueur a toujours des vies et dans la négative met le jeu en pause
{
	if(un->vie<=0)
	{
		pauseVie = true;
		
	}
	if(pauseVie==false)
	{
		glutPostRedisplay();
		glutTimerFunc(50, updateVie, 0);
	}
}


void updateCollisions(int valeur) //fonction qui vérifie s'il y a des collisions entre les tirs et les ennemis
{
	ennemi baseE = es->starList;
	tirsP baseP = t->starList;
	if (es->starList != NULL && t->starList != NULL)
	{
		checkCollision(baseE, baseP, un);
		if (t->starList->nextptr != NULL)
			{
				baseP = baseP->nextptr;	
				checkCollision(baseE, baseP, un);
				while (baseP->nextptr != NULL)
				{
					baseP = baseP->nextptr;
					checkCollision(baseE, baseP, un);
				}
			}
		if (es->starList->nextptr != NULL)
		{
			baseE = baseE->nextptr;
			baseP = t->starList;
			checkCollision(baseE, baseP, un);
			if (t->starList->nextptr != NULL)
			{
				baseP = baseP->nextptr;
				checkCollision (baseE, baseP, un);
				while (baseP->nextptr != NULL)
				{
					baseP = baseP->nextptr;
					checkCollision(baseE, baseP, un);
				}
			}
			while (baseE->nextptr != NULL)
			{
				baseE = baseE->nextptr;
				baseP = t->starList;
				checkCollision(baseE, baseP, un);
				if (t->starList->nextptr != NULL)
				{
					baseP = baseP->nextptr;
					checkCollision (baseE, baseP, un);
					while (baseP->nextptr != NULL)
					{
						baseP = baseP->nextptr;
						checkCollision(baseE, baseP, un);
					}
				}
			}
		}
	}
	glutPostRedisplay();
	glutTimerFunc(50, updateCollisions, 0);
}

void updateEnnemis(int valeur) //fonction qui permet aux ennemis de se déplacer et de faire perdre une vie au joueur si l'ennemi arrive en bas + rend l'ennemi inactif pour que la fonction de suppression le supprime
{
	q = es->starList;
	if (es->starList != NULL)
	{
		q->coord.y += 1;
		if (q->coord.y > 28)
		{
			q->coord.y = 2;
			q->active = false;
			un->vie -= 1;

		}
		while (q->nextptr != NULL)
		{
			q = q->nextptr;
			q->coord.y +=1;
			if (q->coord.y > 28)
			{
				q->coord.y = 2;
				q->active = false;
				un->vie -= 1;
			}
		}
	}
	if(pauseVie==false)
	{
		glutPostRedisplay();
		glutTimerFunc(250, updateEnnemis, 1); //permet de changer la vitesse de mouvement des ennemis
	}
	
}

void updateNewEnnemis(int valeur) //fonction qui se chargera de créer des ennemis toutes les 3.5secondes
{
	ennemi new = createEnnemi(taille_x);
	insertionEnnemis(es, new);
	if(pauseVie==false)
	{
	glutPostRedisplay();
	glutTimerFunc(3500, updateNewEnnemis, 3);
	}
}

void updateTirs(int valeur) //fonction qui gère le déplacement des tirs du joueur
{
	r = t->starList;
	if (t->starList != NULL)
	{
		r->coord.y -= 1;
		
		if (r->coord.y < 2)
		{
			r->coord.y = 88;
			r->active = false;
		}
		while (r->nextptr != NULL)
		{
			r = r->nextptr;
			r->coord.y -= 1;
			
			if (r->coord.y < 2)
			{
				r->coord.y = 88;
				r->active = false;
			}
		}
	}
	if(pauseVie==false)
	{
		glutPostRedisplay();
		glutTimerFunc(50, updateTirs, 2);
	}
}

void updateDeleateEnnemis(int valeur) //fonction qui s'occupe de supprimer les ennemis
{
	if (es->starList != NULL || es->endList != NULL)
	{
		suppressionEnnemis(es, test);
	}
	if(pauseVie==false)
	{
		glutPostRedisplay();
		glutTimerFunc(200, updateDeleateEnnemis, 4);
	}
}

void updateDeleteTirs(int valeur) //fonction qui s'occupe de supprimer les tirs
{
	if (t->starList != NULL || t->endList != NULL)
	{
		suppressionTirs(t, test);
	}
	if(pauseVie==false)
	{
		glutPostRedisplay();
		glutTimerFunc(50, updateDeleteTirs, 5);
	}
}

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int width,int heigth)
{
	glViewport(0, 0, width, heigth);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, heigth, 0);
}

void Display()
{
	
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	jeu(taille_x, taille_y, un, es, t, pauseVie);
	glFlush();
}

int main(int argc, char *argv[])
{
	taille_map(&taille_x, &taille_y);
	load_map(&taille_x, &taille_y);
	afficher_map(&taille_x, &taille_y);
	un = creation_joueur(taille_x, taille_y);
	es = initialListEnnemis();
	t = initialListeTirs();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize((taille_x)*taille_carre, (taille_y)*taille_carre);

	glutCreateWindow("Wing2Wing");
	initRendering();

	glutDisplayFunc(Display);
	glutReshapeFunc(handleResize);
	
	
		glutTimerFunc(50, updateCollisions, 0);   //permet de modifier le temps à partir de quand ça commence
		glutTimerFunc(10, updateEnnemis, 1);
		glutTimerFunc(30, updateNewEnnemis, 3);
		glutTimerFunc(50, updateTirs, 2);
		glutTimerFunc(20, updateDeleateEnnemis, 4);
		glutTimerFunc(50, updateDeleteTirs, 5);
		glutTimerFunc(50, updateVie, 0);
	
	
	

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();


	return 0;
}



