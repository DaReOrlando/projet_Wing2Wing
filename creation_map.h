#ifndef _CREATION_MAP_H_
#define _CREATION_MAP_H_

#include "load_map.h"
#include "joueur.h"
#include "ennemis.h"
#include "tirs.h"

void creation_murs(int taille_x, int taille_y); //permet de construire les murs du jeu taille_ et taille_y > 0
void afficher_joueur(joueur un); //permet d'afficher le joueur
void afficher_ennemi(ennemi e); //permet d'afficher un ennemi
void afficherTirsAllie(tirsP p); //permet d'afficher les tirs du joueurs
void afficherTousEnnemis(listeEnnemi es); //gère l'affichage de l'ensemble des ennemis
void afficherTousTirsAllie(listetirsP t); //gère l'affichage de l'ensemble des tirs du joueur
void afficherScore(joueur un, int x, int y, void *font); //permet d'afficher le score
void afficherVie(joueur un); //permet d'afficher la vie du joueur
void afficherGameOver(joueur un, int x, int y, void *font); //permet d'afficher l'écran de game over


#endif
