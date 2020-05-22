/*
	Ecrire un algorithme/programme permettant de résoudre le problème suivant :
	– Données : un tableau contenant 10 entiers
	– Résultat : “vrai” si les entiers sont consécutifs et “faux” sinon Rappel : deux entiers x et y
	sont consécutifs si et seulement si y = x +1.
*/

#include <stdio.h>

void is_consecutif(int *tab)
{
	int i = -1;
	while(++i < 9)
		if(tab[i] != tab[i+1] - 1)
		{
			printf("faux");
			break;
		}
	if (i == 9)
		printf("vrai");
}

int main(void)
{
	int tab[] = {0,1,2,3,4,5,6,7,8,9};
	is_consecutif(tab);
	return(0);
}
