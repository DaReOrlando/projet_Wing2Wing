
#ifndef _LOAD_MAP_H_
#define _LOAD_MAP_H_


#include <stdbool.h>

#define taille_carre 20.0 //définition de la taille du joueur, des ennemis et des murs
#define Shoot_size 10.0 //définition de la taille des tirs

char **map; //déclaration de la variable qui contiendra le tableau à deux dimensions représentant la map


void taille_map(int *taille_x, int *taille_y); //fonction qui calcule la taille de la map et insère ces valeurs dans taille_x et taille_y
bool load_map(int *taille_x, int *taille_y); //fonction qui charge la map en .txt dans la variable map
void afficher_map (int *taille_x, int *taille_y); //fonction qui permet d'afficher la map sur le terminal

#endif
