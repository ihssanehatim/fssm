/*
	Ecrire un algorithme/programme permettant de saisir 10 valeurs et qui les range au fur et à
	mesure dans un tableau.
*/

#include <stdio.h>

void tri_esc(int *tab)
{
	int i = 0, j, tmp;
	while(++i < 9)
	{
		j = i + 1;
		while(++j <= 9)
		{
			if(tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}

#include <stdio.h>

int main(void)
{
	int tab[10] = {0,1,2,33,4,15,6,7,8,9};
	int i = -1;
	tri_esc(tab);
	while(++i <= 9)
		printf("%d\t",tab[i]);
	printf("\n");
	return (0);
}
