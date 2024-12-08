#include <stdio.h>

int main() {
	float r = 0;
	float pi = 3.14159;
	printf("Digita il raggio di una circonferenza e trovero' diametro area e perimetro!\n");
	scanf("%f", &r);
	
	float d = 2 * r;
	float p = 2 * r * pi;
	float a = r * r * pi;
	printf("Perfetto, fammi fare i miei calcoli ora... \nOK! Dunque, il suo diametro e' %.2fcm, il suo perimetro e' %.2fcm e la sua area e' %.2fcm quadrati\nScusa l'attesa\n", d, p, a);

	system("pause");

	return 0;
}