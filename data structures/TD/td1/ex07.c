/*
	Ecrire un algorithme/programme qui inverse l’ordre d’un tableau des 10 entiers triés. En
	d’autres termes, si le tableau est trié du plus petit au plus grand, alors l’algorithme retourne le
	tableau trié du plus grand au plus petit ; réciproquement, si le tableau est trié du plus grand au
	plus petit, alors l’algorithme retourne le tableau trié du plus petit au plus grand.
	Note : dans la correction vous pouvez utiliser la fonction permuter qui échange les valeurs de
	deux variables.
*/

#include <stdio.h>

void tri_esc(int *tab)
{
	int i = -1, j, tmp;
	while(++i < 9)
	{
		j = i;
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

void tri_desc(int *tab)
{
	int i = -1, j, tmp;
	while(++i <= 9)
	{
		j = i;
		while(++j <= 9)
		{
			if(tab[i] < tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}

int main(void)
{
	int diff = 0;
	int tab[10] = {9,8,7,6,5,4,3,2,1,0};
	int i = -1;
	while(++i < 9)
		if((diff = tab[0] - tab[i]))
		{
			diff > 0 ? tri_esc(tab) : tri_desc(tab);
			break;
		}
	i = -1;
	while(++i <= 9)
		printf("%d\t",tab[i]);
	printf("\n");
	return (0);
}
