/*
	Un polynôme peut être représenté par une liste chainée dans laquelle chaque nœud contient un
	coefficient, un exposant et un pointeur vers le terme suivant.
		1) Définir une fonction de création d’un polynome (Polynome * CreePolynomeVide()).
		2) Définir une fonction permettant d’ajouter des nœuds à un polynome (void
		AjouterNoeud(Polynome * po, int coef, int exp).
		3) Etablir un algorithme d’addition de deux polynômes (polynome1 et polynome2).
		4) Ecrire le programme C correspondant à vos fonctions et à votre algorithme.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Polynome
{
	float	coeff;
	int		expo;
	struct Polynome	*next;
} Polynome;

Polynome *CreePolynomeVide()
{
	struct Polynome *p = malloc(sizeof(Polynome));
	p->coeff = 0;
	p->expo = 0;
	p->next = NULL;
	return (p);
}

void	AjouterNoeud(Polynome * po, int coef, int exp)
{
	struct  Polynome *p1 = po,*tmp;
	while (p1)
	{
		if (p1->expo == exp)
			p1->coeff += coef;
		else if (p1->expo > exp)
		{
			p1 = p1->next;
			continue;
		}
		else
		{
			tmp = malloc(sizeof(struct Polynome));
			tmp -> coeff = coef;
			tmp -> expo = exp;
			tmp -> next = p1;
			p1 = tmp;
		}
		break;
	}
}	

Polynome	*add(Polynome *p1, Polynome *p2)
{
		Polynome *p, *p0 = CreePolynomeVide();
		for(int i = 0; i < 2; i++)
		{
			p = (i==0) ? p1 : p2;
			while(p)
			{
				AjouterNoeud( p0, p->coeff, p->expo);
				p = p->next;
			}
		}
	return (p0);
			
}

int main (void)
{
	Polynome *p  = CreePolynomeVide();
	AjouterNoeud(p, 1,1);
	return (0);
}

