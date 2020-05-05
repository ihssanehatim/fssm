/*	Ecrire un algorithme/programme permettant de résoudre le problème suivant :
	– Données : deux vecteurs p et q dans un espace (Euclidien) à 3 dimensions
	– Résultat : le produit scalaire de p et q
*/

#include <stdio.h>

int main(void)
{
	int p[3],q[3];

	printf("\np[x] = ");scanf("%d",&p[0]);
	printf("\np[y] = ");scanf("%d",&p[1]);
	printf("\np[z] = ");scanf("%d",&p[2]);
	printf("\nq[x] = ");scanf("%d",&q[0]);
	printf("\nq[y] = ");scanf("%d",&q[1]);
	printf("\nq[z] = ");scanf("%d",&q[2]);
	printf("{%d,%d,%d} * {%d,%d,%d} = {%d,%d,%d}\n",p[0],p[1],p[2],q[0],q[1],q[2],p[0]*q[0],p[1]*q[1],p[2]*q[2]);
	return (0);
}
