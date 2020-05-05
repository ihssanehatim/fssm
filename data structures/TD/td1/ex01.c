/*
	U(n+2) = U(n) + U(n+1)
    Les deux premiers termes U1 et U2 étant donnés.
	Ecrire un algorithme/programme qui permet de calculer un terme quelconque de cette suite.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)

{
	int n, U1, U2, *UN, i;
	
	i = 2;
	printf("\nU1=");scanf("%d",&U1);
	printf("\nU2=");scanf("%d",&U2);
	printf("\n n=");scanf("%d",&n);
	UN = (int*)malloc(sizeof(int) * (n + 1));
	UN[1] = U1;
	UN[2] = U2;
	while(++i <= n)
		UN[i] = UN[i-1] + UN[i - 2];
	printf("\nU[%d] = %d\n",n, UN[n]);
	free(UN);
	return (0);
}
