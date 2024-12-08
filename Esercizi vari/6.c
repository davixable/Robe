#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int r1, c1, r2, c2;

	int m1[7][7] = { 0 };
	int m2[7][7] = { 0 };
	int m3[7][7] = { 0 };

	printf("Inserisci il numero di righe e colonne (max. 7) della prima matrice: \n");
	scanf("%d %d", &r1, &c1);
	printf("Inserisci il numero di righe e colonne (max. 7) della seconda matrice: \n");
	scanf("%d %d", &r2, &c2);

	if (c1 != r2) {
		printf("Le colonne della prima devono essere uguali alle righe della seconda! \n");
		system("PAUSE");
		return 0;
	}

	printf("Ok, partiamo dalla prima matrice \n");

	for (int i = 0; i < r1; i++) {
		printf("Inserisci i coefficienti della riga #%d \n", i + 1);
		for (int j = 0; j < c1; j++) {
			scanf("%d", &m1[i][j]);
		}
	}

	printf("Adesso spostiamoci alla seconda matrice \n");

	for (int i = 0; i < r2; i++) {
		printf("Inserisci i coefficienti della riga #%d \n", i + 1);
		for (int j = 0; j < c2; j++) {
			scanf("%d", &m2[i][j]);
		}
	}

	//Prodotto riga per colonna (please work)

	for (int i = 0; i < r1; i++) {  //riga r1
		for (int j = 0; j < c2; j++) {  //colonna c2
			for (int k = 0; k < c1; k++) {  //elementi
				m3[i][j] = m3[i][j] + (m1[i][k] * m2[k][j]);
			}
		}
	}
	
	printf("\n");
	for (int i = 0; i < r1; i++) {  //riga
		for (int j = 0; j < c2; j++) {  //colonna
			printf("%d  ", m3[i][j]); 

		}
		printf("\n");
	}



	return 0;
}