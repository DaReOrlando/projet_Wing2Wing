#ifndef _JEU_H_
#define _JEU_H_

#include <stdio.h>
#include <stdlib.h>

void Keyboard(unsigned char key, int x, int y); //fonction qui récupère les inputs clavier
char *transformationScore(joueur un); //fonction qui stoque une phrase contenant un int dans une chaine de caractère et la renvoie
char *transformationVie(joueur un); //fonction qui stoque une phrase contenant un int dans une chaine de caractère et la renvoie
void jeu(int taille_x, int taille_y, joueur un, listeEnnemi es, listetirsP  t, bool pauseVie); //grosse fonction qui appelle toutes les fonctions d'affichage + gestion du déplacement du joueur
void checkCollision (ennemi q, tirsP r, joueur un); //fonction qui vérifie la collision entre tirs joueur et ennemis et augmente le score du joueur en cas de collision

#endif