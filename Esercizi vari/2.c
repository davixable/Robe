#include <stdio.h>

int main() {
	int n1 = 1;
	int n2 = 1;
	printf("Digita 2 numeri \n");

	scanf("%d", &n1);
	scanf("%d", &n2);

	if (n1 % n2 != 0 && n2 % n1 != 0) {
		printf("Nessuno dei due numeri e' multiplo dell'altro\n");
	};

	if (n1%n2 == 0) {
		if (n1 > n2) {
			printf("Il numero %d e' multiplo di %d\n", n1, n2);
		};
	};
	
	if (n2%n1 == 0) {
		if (n2 > n1) {
			printf("Il numero %d e' multiplo di %d\n", n2, n1);
		};
	};

	system ("pause");

	return 0;
}