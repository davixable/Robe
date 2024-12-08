#include <stdio.h>

//Conteggio dei numeri pari e dispari in un array

int main() {
	int n[4];
	int pari[4];
	int dispari[4];
	int lenp = 0;
	int lend = 0;

	printf("Digita 4 numeri \n");
	scanf("%d %d %d %d", &n[0], &n[1], &n[2], &n[3]);

	for (int i = 0; i < 4; i++) {
		if (n[i] % 2 == 0) {
			pari[lenp] = n[i];
			lenp++;
		}
		else {
			dispari[lend] = n[i];

			lend++;
		}
	}
	printf("I numeri pari sono: ");

	for (int i = 0; i < lenp; i++) {
		printf("%d ", pari[i]);

	}
	printf("\nI numeri dispari sono: ");

	for (int i = 0; i < lend; i++) {
		printf("%d ", dispari[i]);
	}

	return 0;
}