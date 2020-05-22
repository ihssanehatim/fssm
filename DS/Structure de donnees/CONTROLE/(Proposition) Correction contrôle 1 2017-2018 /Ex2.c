#include <stdio.h>
#include <stdlib.h>
// TDA 
typedef struct Element Element ;
struct Element 
	{
	char c;                          // {0,1}
	Element *suivant;
	};
typedef struct liste_C Liste ;
struct liste_C
	{
	Element *tete;
	}; 
	
	//Initialisation de la liste chaînée
Liste *Initialisation(char ch)
{
	Liste *liste = malloc(sizeof(*liste)) ; 	
	Element *element = malloc(sizeof(*element)) ;
	element -> c =ch;
	element -> suivant =NULL ;
	liste -> tete = element ;
	return liste;
}


//Insertion d'un nouvel élement en fin de liste
void Insertion(Liste *liste , int ch)
{
Element *nouveau = malloc(sizeof(*nouveau));
Element *actuel = liste -> tete ;
if ( nouveau == NULL || liste == NULL)
	{
	exit(0);
	}
nouveau -> c = ch ;
nouveau -> suivant = NULL ;
while (actuel -> suivant != NULL)
	{
	actuel = actuel -> suivant ;
	}
actuel -> suivant = nouveau; 
}

void Affichage(Liste *liste)
{
if (liste == NULL)  
	{exit(0);}
Element *actuel = liste -> tete ;
while (actuel != NULL)
	{
	printf("%c  -> ", actuel -> c );
	actuel = actuel -> suivant ;
	}
printf("NULL\n");
}

	//Fonction appartient
int appartient(Liste *liste , char ch)
	{
	Element *actuel = liste ->tete ;
	while (actuel -> suivant != NULL)
		{
		if (actuel -> c == ch) return 1;
		actuel = actuel -> suivant ;
		}
	if (actuel -> c == ch) return 1;
	return 0;
	}
	
	//Fonction supprimer_occurences_multiples
Liste *supprimer_occurences_multiples(Liste *liste)
	{
	Element *rech = liste -> tete;
	Element *actuel = rech -> suivant ;
	Element *precedent= liste-> tete ;
	while (rech -> suivant != NULL)
		{
			while ( (appartient(liste,rech -> c)) && (actuel != NULL ))
				{
					if (rech -> c == actuel -> c)
					{														    
						precedent -> suivant = actuel -> suivant ;              
						free(actuel);
						actuel = precedent -> suivant ; 
					}
					else 
					{
						actuel = actuel -> suivant;
						precedent=precedent -> suivant;
					}
				}
			rech = rech -> suivant ;
			precedent = rech ;
			actuel = rech -> suivant ;
		}
	return liste;
	}
	
	// Programme principal	
void main()
{
	Liste *maliste=Initialisation('a');
	Insertion (maliste,'b');
	Insertion (maliste,'c');
	Insertion (maliste,'b');
	Insertion (maliste,'b');
	Insertion (maliste,'f');
	Insertion (maliste,'a');
	Insertion (maliste,'c');
	Insertion (maliste,'a');
	Insertion (maliste,'b');
	Insertion (maliste,'a');
	Affichage(maliste);
	printf("Recherche:%d\n",appartient(maliste,'v'));
	Liste *maliste2=supprimer_occurences_multiples(maliste);
	Affichage(maliste2);
}
