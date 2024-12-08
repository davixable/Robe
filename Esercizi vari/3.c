/*Write a program that inputs three different integers from the keyboard, then displays the sum, the average, the
product, the smallest and the largest of these numbers. Use only the single-selection form of the if statement you
learned in this chapter.*/

#include <stdio.h>

int main() {
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;

	printf("Digita 3 numeri e faro' cose ;)\n");
	scanf("%d %d %d", &n1, &n2, &n3);

	int sum = 0;
	int media = 0;
	sum = n1 + n2 + n3;
	printf("DUNQUE. La somma dei numeri da te digitati e' %d, la loro media e' %d ed il loro prodotto e' %d\n", sum, sum / 3, n1 * n2 * n3);

	int smallest = 0;
	int largest = 0;

	//n1 piu' grande
	if (n1 > n2 && n1 > n3) {
		largest = n1;
		printf("Inoltre, %d e' il piu' grande\n", largest);
	}

	//n1 piu' piccolo
	if (n1 < n2 && n1 < n3) {
		smallest = n1;
			printf("Inoltre, %d e' il piu' piccolo\n", smallest);
	}

	//n2 piu' grande
	if (n2 > n1 && n2 > n3) {
		largest = n2;
		printf(" Inoltre, %d e' il piu' grande\n", largest);
	}

	//n2 piu' piccolo
	if (n2 < n1 && n2 < n3) {
		smallest = n2;
		printf("Inoltre, % d e' il piu' piccolo\n", smallest);
	}

	//n3 piu' grande
	if (n3 > n1 && n3 > n2) {
		largest = n3;
		printf("Inoltre, %d e' il piu' grande\n", largest);
	}

	//n3 piu' piccolo
	if (n3 < n2 && n3 < n1) {
		smallest = n3;
		printf("Inoltre, %d e' il piu' piccolo\n", smallest);
	}
	return 0;

}