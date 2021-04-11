#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "load_map.h"

void taille_map(int *taille_x, int *taille_y) //permet de calculer la taille de la map afin de pouvoir la changer. Condition : la dernière ligne et la dernière colonne doivent être remplies de '/'
{
	FILE *f = NULL;
	f = fopen("map.txt", "r"); //ouverture du fichier map.txt en mode lecture
	if(f == NULL) //on vérifie que le fichier existe et qu'il est bien stocké dans f
	{
		printf("Le fichier n'a pas été trouvé\n" );
	}
	else
	{
		char c = fgetc(f);
		char ancien_c =' ';
		int i = -1, j = 0;
		while(c != '/')
		{
			j++;
			c = fgetc(f);
		}
		while(c !='/' || ancien_c != '/')
		{
			if(c=='/')
			{
				i++;

			}

			ancien_c = c;
			c = fgetc(f);
			
			
			
		}
		*taille_x = j;
		*taille_y = i;
	}
	fclose(f);
	
}


bool load_map(int *taille_x, int *taille_y)  //Fonction qui ouvre un fichier texte et le charge dans un tableau à deux dimensions
{
	map = malloc(sizeof(char *) * (*taille_y)); //Allocation de mémoire pour x ligne 
	FILE *f = NULL;
	f = fopen("map.txt", "r"); //ouverture du fichier map.txt en mode lecture
	if(f == NULL) //on vérifie que le fichier existe et qu'il est bien stocké dans f
	{
		printf("Le fichier n'a pas été trouvé\n" );
		return false;
	}

	char c;
	int i = 0, j = 0;

	for(i = 0; i < (*taille_y); i++)
	{
		*(map + i) = malloc(sizeof(char *) * (*taille_x)); //allocation de mémoire pour y colonnes à chaque ligne
		for(j = 0; j < (*taille_x); j++)
		{
			c = fgetc(f);
			*(*(map + i) + j) = c;//permet de remplir chaque case d'un tableau avec un caractère venant du fichier ouvert
		}
		fgetc(f); //permet de passer 
		fgetc(f);
	}

	fclose(f); //fermeture du fichier

	

	

return true;

}

void afficher_map(int *taille_x, int *taille_y) //Permet d'afficher le tableau map afin de vérifier qu'il a été enregistré correctement
{
	int i = 0, j = 0;
	printf("\n");
	for(i = 0; i < (*taille_y); i++)
	{
		for(j = 0; j < (*taille_x); j++)
		{
			printf("%c", *(*(map + i) + j));
		}
		printf("\n");
	}
}
