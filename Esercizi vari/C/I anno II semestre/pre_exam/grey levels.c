/*
simulazione immagine con livelli di grigio
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 16
#define M 16

typedef struct Node {
	unsigned char value;
	int x;
	int y;
	struct Node* next;
}Node;

void create_image(unsigned char** I);
void print_image(unsigned char** I);
void create_lists(unsigned char** I, Node** liste, int L);
int count_nodes(Node* head);

void create_image(unsigned char** I) {
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			I[i][j] = (unsigned char)rand() % 256;
		}
	}
}

void print_image(unsigned char** I) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", I[i][j]);
		}
		puts("");
	}
}

void create_lists(unsigned char** I, Node** liste, int L) {
	int D = 256 / L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			unsigned char val = I[i][j];
			Node* new_node = malloc(sizeof(Node));
			new_node->value = val;
			new_node->x = i;
			new_node->y = j;
			int idx = (int)val / D;
			new_node->next = liste[idx];
			liste[idx] = new_node;
		}
	}
}

void print_lists(Node** liste, int L) {
	for (int i = 0; i < L; i++) {
		Node* curr = liste[i];
		printf("\nLista #%d: ", i);
		while (curr) {
			printf("%d -> ", curr->value);
			curr = curr->next;
		}
		puts("");
	}
}

int count_nodes(Node* head){
	int count = 0;
	if (head == NULL) {
		return count;
	}
	while (head) {
		count++;
		head = head->next;
	}
	return count;
}

int main() {
	int L;
	unsigned char** I = malloc(N * sizeof(unsigned char*));
	for (int i = 0; i < M; i++) {
		I[i] = malloc(M * sizeof(unsigned char));
	}
	create_image(I);
	print_image(I);
	printf("Quanti sotto-livelli di grigio vuoi? ");
	scanf("%d", &L);
	Node** liste = malloc(L * sizeof(Node*));
	for (int i = 0; i < L; i++) {
		liste[i] = NULL;
	}
	create_lists(I, liste, L);
	print_lists(liste, L);
	int* number_of_nodes = malloc(sizeof(int) * L);
	for (int i = 0; i < L; i++) {
		number_of_nodes[i] = count_nodes(liste[i]);
		printf("Ci sono %d nodi nella lista #%d.\n", number_of_nodes[i], i);
	}
	puts("");
}