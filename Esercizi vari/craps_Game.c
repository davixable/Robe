#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>	

char nomi_giocatori[50][50];
int punteggi[50][2];  //prima colonna per le partite giocate, seconda colonna per le manche vinte
int numero_giocatori = 0;

int dice_Roll();
int find_Player();
int print_Scoreboard();

int main() {
	int somma, punteggio, indice_giocatore=0, game_status = 0; //game_status: 0 per CONTINUE , 1 per WIN, 2 per LOSE e 3 per TIE
	char nome[50];								
	srand(time(NULL));


	do {
		printf("Prima di cominciare, inserisci il tuo nome (max. 50 caratteri, END per chiudere):\n");
		scanf("%49s", nome);
		getchar();

		if (strcmp(nome, "END") == 0) {
			if (numero_giocatori >=1) {
				print_Scoreboard();
			}
			return 0;
		}

		indice_giocatore = find_Player(nome);
		if (indice_giocatore == -1) {
			strcpy(nomi_giocatori[numero_giocatori], nome);
			punteggi[numero_giocatori][0] = 0;
			punteggi[numero_giocatori][1] = 0;
			indice_giocatore = numero_giocatori;
			numero_giocatori++;

		}
		else {
			printf("Bentornato/a %s!\nPremi invio per tirare i dadi: ", nome);
			getchar();
		}

		punteggi[indice_giocatore][0]++;
		game_status = 0;
		while (game_status == 0) {

			somma = dice_Roll();

			switch (somma) {
			case 7:
			case 11:
				printf("Hai fatto %d, hai vinto!\n", somma);
				punteggi[indice_giocatore][1]++;
				game_status = 1;
				break;
			case 2:
			case 3:
			case 12:
				printf("Hai fatto %d, hai perso!\n", somma);
				game_status = 2;
				break;
			default:
				printf("Hai fatto %d\n", somma);
				punteggio = somma;
				game_status = 3;

				break;
			}
		}
		while (game_status == 3) {
			printf("Premi invio per fare un altro lancio: ");
			getchar();

			somma = dice_Roll();
			if (punteggio == somma) {
				printf("Hai fatto %d, hai vinto!\n", somma);
				game_status = 1;
				punteggi[indice_giocatore][1]++;
			}
			if (somma == 7) {
				printf("Hai fatto %d, hai perso!\n", somma);
				game_status = 2;
			}
			
		}
		for (int i = 0; i < numero_giocatori; i++) {
			if (punteggi[indice_giocatore][1] == 3) {
				printf("Complimenti %s, hai vinto 3 round! Vinci la partita!\n", nome);
				print_Scoreboard();
				return 0;
			}
		}

		printf("Ok! Sta per cominciare un'altra manche!\n");
	} while (1);
}


int dice_Roll() {
	int dice_1, dice_2, somma;
	dice_1 = 1 + rand() % 6;
	dice_2 = 1 + rand() % 6;
	somma = dice_1 + dice_2;

	printf("Sono usciti %d e %d.\n", dice_1, dice_2);

	return somma;
}

int find_Player(char* nome) {
	for (int i = 0; i < numero_giocatori; i++) {
		if (strcmp(nomi_giocatori[i], nome) == 0) {
			return i; //giocatore trovato all'indice i
		}
	}
	return -1; //giocatore non trovato (nuovo giocatore)
}

int print_Scoreboard() {
	printf("\n**************\n**************\n");
	printf("CLASSIFICA:\n");
	
	for (int i = 0; i < numero_giocatori; i++) {
		printf("%s: hai giocato %d partita/e e ne hai vinte %d.\n", nomi_giocatori[i], punteggi[i][0], punteggi[i][1]);

	}
}
