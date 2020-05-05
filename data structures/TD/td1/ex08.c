/*
	Ecrire un algorithme/programme qui calcule le plus grand écart dans un tableau d’entiers.
	Rappel : l’écart entre deux entiers x et y est la valeur absolue de leur différence |x − y|.
*/

#include <stdio.h>
#include <math.h>

int main()
{
	int i = -1,j, ecart,tab[] = {1,2,3,4,5,6,7,8,9,0};
	ecart = fabs(tab[0] - tab[1]);
	while(++i < 9)
	{
		j = i;
		while(++j <= 9)
		{
			if(fabs(tab[i] - tab[j]) > ecart)
				ecart = tab[i] - tab[j];
		}
	}
	printf("ecart = %d\n",ecart);
	return (0);
}
