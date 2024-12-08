/*Simulazione del problema di Monty Hall*/
#include <stdio.h>
#include <stdlib.h>

int main() {
	int tentativi=1000,porta_scelta1, porta_scelta2, porta_giusta, porta_rimossa, vincita_con_cambio=0, vincita_senza_cambio=0;

	srand(time(NULL));
	for (int i = 0; i < tentativi; i++) {
		porta_giusta = rand() % 3;
		porta_scelta1 = rand() % 3;

		do {
			porta_rimossa = rand() % 3;
		} while (porta_rimossa == porta_giusta || porta_rimossa == porta_scelta1);

		do {
			porta_scelta2 = rand() % 3;
		} while (porta_scelta2 == porta_scelta1 || porta_scelta2 == porta_rimossa);

		if (porta_giusta == porta_scelta2) {
			vincita_con_cambio++;
		}
		if (porta_giusta == porta_scelta1) {
			vincita_senza_cambio++;
		}
	}

	printf("La percentuale di vincita CAMBIANDO la porta e' del %0.2f%% percento\n", (float)vincita_con_cambio / tentativi * 100);
	printf("La percentuale di vincita NON cambiando la porta e' del %0.2f%% percento\n", (float)vincita_senza_cambio / tentativi * 100);
}
