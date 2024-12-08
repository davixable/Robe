#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int m1[7][7] = { 0 };
	int m2[7][7] = { 0 };
	int r, c;
	int simmetrica = 1;

	printf("Inserisci il numero di righe e colonne della matrice: \n");
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++) {  //numero riga
		printf("Inserisci i coefficienti della riga #%d \n", i + 1);

		for (int j = 0; j < c; j++) { //elementi riga
			scanf("%d", &m1[i][j]);
			m2[i][j] = m1[i][j];
		}
	}
	
	//matrice trasposta
	printf("La trasposta della matrice e': \n");
	
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			m1[j][i] = m1[j][i];

			printf("%d ", m1[j][i]);
		}
		printf("\n");
	}

	//check if A=A'

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			if (m1[j][i] != m2[i][j]) {
				simmetrica = 0;
				break;
			}
		}
		if (!simmetrica) break;
	}

	if (simmetrica) {
		printf("\nLa matrice e' simmetrica!\n");
	}
	else
		printf("\nLa matrice non e' simmetrica!\n");
	return 0;
}