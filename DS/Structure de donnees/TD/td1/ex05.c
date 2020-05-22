/*
	Ecrire un algorithme/programme permettant de résoudre le problème suivant :
	– Données : un tableau contenant 10 entiers
	– Résultat : “vrai” si le tableau est trié du plus petit au plus grand et “faux” sinon
*/

#include <stdio.h>

void is_consecutif(int *tab)
{
	int i = -1;
	while(++i < 9)
		if(tab[i] > tab[i+1])
		{
			printf("faux");
			break;
		}
	if (i == 9)
		printf("vrai");
}

int main(void)
{
	int tab[] = {0,1,2,2,4,5,6,7,8,9};
	is_consecutif(tab);
	return(0);
}
