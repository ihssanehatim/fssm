#include <stdio.h>
#include <stdlib.h>
// TDA 
typedef struct Element Element ;
struct Element 
	{
	int valeur;                          // {0,1}
	Element *suivant;
	};
typedef struct liste_int Liste ;
struct liste_int
	{
	Element *tete;
	};
	
	//Initialisation de la liste chaînée
Liste *Initialisation(int init)
{
	Liste *liste = malloc(sizeof(*liste)) ; 	
	Element *element = malloc(sizeof(*element)) ;
	element -> valeur =init;
	element -> suivant =NULL ;
	liste -> tete = element ;
	return liste;
}
	//Insertion d'un nouvel élement en fin de liste
void Insertion(Liste *liste , int Nnb)
{
Element *nouveau = malloc(sizeof(*nouveau));
Element *actuel = liste -> tete ;
if ( nouveau == NULL || liste == NULL)
	{
	exit(0);
	}
nouveau -> valeur = Nnb ;
nouveau -> suivant = NULL ;
while (actuel -> suivant != NULL)
	{
	actuel = actuel -> suivant ;
	}
actuel -> suivant = nouveau; 
}
	//Affichage de la liste
void Affichage(Liste *liste)
{
if (liste == NULL)  
	{exit(0);}
Element *actuel = liste -> tete ;
while (actuel != NULL)
	{
	printf("%d  -> ", actuel -> valeur );
	actuel = actuel -> suivant ;
	}
printf("NULL\n");
}
	//Fonction estEquilibre
int estEquilibre(Liste *liste)
	{
	int C0=0,C1=0;
	Element *element=liste -> tete ;
	while (element != NULL)
		{
			if (element -> valeur == 0) C0++;	
			else if (element -> valeur == 1) C1++;
			element = element -> suivant;
		}
	if (C0 == C1) return 0;
	else return (C0-C1);
	}

	//Fonction equilibrer
Liste *equilibrer(Liste *liste)
	{
	while (estEquilibre(liste) != 0)
		{
			if (estEquilibre(liste) > 0) Insertion(liste,1);
			else Insertion(liste,0);
		}
	return liste;
	}


	// Programme principal	
	void main()
{
Liste *maliste=Initialisation(0);
Insertion (maliste,0);
Insertion (maliste,0);
Insertion (maliste,0);
Insertion (maliste,0);
Insertion (maliste,1);
Affichage(maliste);
printf("Equilibre : %d\n",estEquilibre(maliste));
equilibrer(maliste);
Affichage(maliste);
}

