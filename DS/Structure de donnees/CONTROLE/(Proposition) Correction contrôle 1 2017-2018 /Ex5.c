#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h> 
//TDA 
typedef struct Noeud Noeud ;
struct Noeud
	{
	int V;
	Noeud *droite;
	Noeud *gauche;
	};
	
typedef struct Abr Abr ;
 struct Abr
 	{
 	Noeud *Racine;
 	};

//Fonctions 
	//Initialisation 
Abr  *Initialisation(void)
	{
	Abr *abr=malloc(sizeof(*abr));
	abr -> Racine = NULL ;
	return   abr ;
	}
	
	//Créer noeud
Noeud *Creernoeud(int Nv)
	{
	Noeud  *noeud=malloc(sizeof(*noeud));
	noeud->V=Nv;
	noeud->gauche=noeud->droite=NULL;
	return noeud;
	}
	
	//Arbre vide 
bool ABRvide(Abr *abr)
	{
	if (abr -> Racine == NULL) return true ;
	else return false ;
	}
		
	//Ajouter élément 
int ajout(int Nv ,Noeud *R,Abr *abr)
	{
	if  ( ABRvide(abr) )  
					{
					Noeud *noeud=Creernoeud(Nv);
					abr -> Racine = noeud ;
					return 1;
					}
	else 
		{
			{  
				if (( Nv > R -> V) && (R -> droite ==NULL) ) 
						{
						Noeud *noeud=Creernoeud(Nv);
						R -> droite = noeud ;
						return 1;
						}
				else if  (( Nv > R -> V) && (R -> droite != NULL))
						{
						R = R -> droite;
						ajout(Nv, R,abr);
						return 1;
						}
		 	}
		 	
		 	{
			 	if (( Nv <= R -> V) && (R -> gauche ==NULL) ) 
				 		{
				 		Noeud *noeud=Creernoeud(Nv);
				 		R -> gauche =noeud ;
				 		return 1;
				 		}
				else if  (( Nv <= R -> V) && (R -> gauche != NULL))
						{
						R = R -> gauche;
						ajout(Nv, R,abr);
						return 1;
						}
		 	}
		}
	}


	//Lecture 
int lecture (Noeud *r)   //lecture(abr -> Racine)
	{
	if (r==NULL)
		return 0 ;
	else        
		{
		lecture(r ->gauche );
		printf("%d\n",r -> V ) ;  
		lecture(r ->droite ); 
		return 1 ;
		}
	}
	
	//Calcul nombre de feuille dans un arbre binaire 
int Nbfeuilles(Noeud *noeud)
	{
	{if (noeud == NULL) return 0;}
	if ( (noeud -> gauche == NULL) && (noeud -> droite == NULL) && ( noeud != NULL )) return 1; 
	else return Nbfeuilles(noeud -> gauche) + Nbfeuilles (noeud -> droite);
	}
	
	//Fonction tableauToABR
Abr *tableauToABR(int Tab[100],int N)
	{
	Abr *arbre=Initialisation();
	for (int i=0;i<N;i++) 
		{ajout(Tab[i],arbre -> Racine ,arbre);}
	return arbre;
	}
	

//Programme principal 
void main()
	{int Tab[100],N,Nbf;                 
	printf("Nombre d'entiers à saisir:");
	scanf("%d",&N);
	for (int i=0;i<N;i++)
		{
		printf("Saisir l'entier %d:",i+1);
		scanf("%d",&Tab[i]);
		}                                                                       
	Abr *arbre=tableauToABR(Tab,N);
	lecture(arbre -> Racine) ;
	Nbf=Nbfeuilles(arbre -> Racine); 
	printf("Nombre de feuilles:%d\n",Nbf);	
	}
	
