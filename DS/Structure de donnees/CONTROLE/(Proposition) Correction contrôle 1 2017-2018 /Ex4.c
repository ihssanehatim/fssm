#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Element Element;
struct Element
	{
	char c;
	Element *suivant ;
	};
typedef struct Tampon Tampon;
struct Tampon
	{
	Element *tete;
	};

	//Initialisation du tampon
Tampon *Initialisation(char ch)
	{
	Tampon *tampon=malloc(sizeof(*tampon));
	Element *element=malloc(sizeof(*element));
	element -> c = ch ;
	element -> suivant = NULL ;
	tampon -> tete = element ;
	return tampon;
	}
	
	//Ajouter chaîne de caractères (empiler les char un par un)
int empiler(Tampon *tampon,char ch)
	{
	Element *element=malloc(sizeof(*element));
	element -> c = ch ;
	element -> suivant = tampon -> tete ; 
	tampon -> tete = element ;	
	return 0;
	}
int ajout(Tampon *tampon)
	{
	char s[100];
	printf("Saisir la commande:");	
	fgets(s,100,stdin);
	for (int i=0;i<strlen(s);i++)
		{
		empiler(tampon,s[i]);
		}
	return 0;	
	}
	
	//Affichage tampon
void Affichage(Tampon *tampon)
	{
	if (tampon == NULL)  
	{exit(0);}
Element *actuel = tampon -> tete ;
while ((actuel != NULL) && (actuel -> c != '$'))
	{
		printf("%c", actuel -> c );
		actuel = actuel -> suivant ;
	}
	printf("\n");
}	
	
	// Transformations
	//Dépiler
void depiler(Tampon *tampon)
	{
	Element *actuel=tampon -> tete;
	tampon -> tete = actuel -> suivant ;
	free(actuel);
	}
Tampon * transformer(Tampon *tampon)
	{
	Element *actuel=tampon -> tete ;
	Tampon *tep=malloc(sizeof*tep);
	while ((actuel != NULL) && (actuel -> c != '$')) 
	{
			{
				if  (actuel -> c == '\n' )	{depiler(tampon);actuel =actuel -> suivant ;}
				else if (actuel -> c == '#')
					{
					depiler(tampon);
					actuel =actuel -> suivant ;
					depiler(tampon);
					actuel =actuel -> suivant ;
					}
				else
					{
				empiler(tep,actuel->c);
				depiler(tampon);
				actuel =actuel -> suivant ;
					}
			}
	}
	return tep ;
	}
	// Programme principal 
void main()
	{
	Tampon *tampon=Initialisation('$');
	ajout(tampon); 
	Tampon *tep=transformer(tampon);
	Affichage(tep);
	}	
	
	

