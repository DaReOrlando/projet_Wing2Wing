#ifndef _JOUEUR_H_
#define _JOUEUR_H_

typedef struct Position //structure pour la position du joueur
{
	int x;
	int y;
}Position;

struct Joueur //stucture du joueur
{
	int vie;
	int degat;
	int score;
	Position coord;

};

typedef struct Joueur *joueur;

joueur creation_joueur(int taille_x, int taille_y); //fonction qui initialise un joueur
void gauche(joueur un); //fonction pour aller à gauche
void droite(joueur un); //fonction pour aller à droite
void haut(joueur un); //fonction pour aller en haut
void bas(joueur un); //fonction pour aller en bas

#endif
