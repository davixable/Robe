#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	float miglia;
	float galloni;
	float avgt = 0;
	float avg[20];
	float avgtot = 0;
	int risposta;
	int i = 0;

	printf("Con questo programma potrai calcolare la media dei tuoi consumi fino a 20 pieni!\n");


		do {
			printf("Scrivi il numero di miglia percorse: \n");
			scanf("%f", &miglia);
			printf("Scrivi il numero di galloni consumati: \n");
			scanf("%f", &galloni);
			printf("Con questo pieno hai percorso in media %.2f miglia/gallone.\n", miglia / galloni);
			printf("Premi 0 per terminare o 1 per continuare\n");
			scanf("%d", &risposta);

			avgt = miglia / galloni;
			avg[i] = avgt;
			i++;

		} while (risposta == 1 && i < 20);

	for (int a = 0; a < i; a++) {

		avgtot = (avgtot + avg[a]);

		}
	printf("La media dei consumi di tutti i viaggi e': %.2f ", avgtot/i);
	return 0;
}
