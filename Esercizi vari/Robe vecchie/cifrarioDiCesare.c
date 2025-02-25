#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getKey();
void cifra(char* str);
void decifra(char* str);

int main() {
	int choice = 0;

	while (1) {
		char str[200];
		printf("Inserisci una stringa (in maiuscolo): \n");
		fgets(str, 200, stdin);
		printf("Premi 1 per cifrare la stringa, 2 per decifrarla, 3 per uscire:\n");
		scanf("%d", &choice);
		if (choice == 1) {
			cifra(str);
		}
		if (choice == 2) {
			decifra(str);
		}
		if (choice == 3) {
			return 0;
		}
		printf("Premi 1 per uscire, 2 per ricominciare:\n");
		scanf("%d", &choice);
		while (getchar() != '\n');
		if (choice == 1) {
			return 0;
		}
	}
}

int getKey() {
	int key = 0;
	while (!key) {
		printf("Scegli una chiave di cifratura: (da 1 a 26)\n");
		scanf("%d", &key);
		if (key >= 1 && key <= 26) {
			break;
		}
		else {
			printf("Chiave non valida.\n");
			key = 0;
		}

	}
	return key;
}

void cifra(char* str) {
	for (int i = 0;str[i] != '\0'; i++) {
		str[i] = toupper(str[i]);
	}
	int key = getKey();

	for (int i = 0;str[i] != '\0'; i++) {
		if (str[i] < 'A' || str[i] > 'Z') {
			continue;
		}
		if ((str[i] + key) > 'Z') {
			str[i] = ('A'-1)+(str[i] + key - 'Z');
		}
		else {
			str[i] = str[i] + key;
		}
	}
	printf("La stringa cifrata e': %s\n", str);
}

void decifra(char* str) {
	int key = getKey();
	for (int i = 0;str[i] != '\0'; i++) {
		str[i] = toupper(str[i]);
	}

	for (int i = 0; str[i]!='\0'; i++) {
		if (str[i] < 'A' || str[i] > 'Z') {
			continue; 
		}
		if ((str[i] - key) < 'A') {
			str[i] = ('Z'+1)-('A' - (str[i] - key));
		}
		else {
			str[i] = str[i] - key;
		}
	}
	printf("La stringa decifrata e': %s\n", str);
}