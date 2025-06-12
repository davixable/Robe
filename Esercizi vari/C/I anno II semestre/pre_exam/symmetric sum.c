/*
input: 10->20->30->40->50
output: 60->60->60->60->60
*/

typedef struct Node {
	int value;
	struct Node* next;
}Node;

void symmetric_sum(Node** head, int nodi) {
	if (*head==NULL) {
		return;
	}
	Node* curr = *head;
	for (int i = 1; i < nodi; i++) {
		curr = curr->next;
	}
	(*head)->value += curr->value;
	curr->value = (*head)->value;
	if (*head == curr || (*head)->next == curr) {
		return;
	}
	symmetric_sum(&((*head)->next), nodi - 2);
}