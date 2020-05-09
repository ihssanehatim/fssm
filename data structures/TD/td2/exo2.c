/*
	On cherche à gérer une liste chainée formée de nombres entiers. Chaque nombre introduit est
	immédiatement placé dans la liste en respectant l’ordre décroissant.
		1) Ecrire un algorithme qui permet de gérer cette liste chainée
			a) Fonction de création de liste InitListe()
			b) Fonction ListeVide()
			c) Fonction ListePleine()
			d) Fonction d’ajout (Liste *L, int nombre)
			e) Fonction de suppression (Liste *L, int nombre)
			f) Fonction d’affichage (Liste * L)
		2) Ecrire le programme C correspondant à votre algorithme.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Liste
{
	int nbr;
	struct Liste *next;
}Liste;

Liste	*InitListe()
{
	Liste *l;
	l = NULL;
	return l;
}

Liste	ListeVide(void)
{
	Liste *l;
	
}
int main(void)
{
	
	return 0;
}
