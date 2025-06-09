/*
data una lista, splittarla in due mezze liste
*/

typedef struct Node {
	int value;
	struct Node* next;
}Node;

void split_list(Node** head, Node** new_head) {
	Node* temp1 = *head;
	Node* temp2 = *head;
	while (temp2->next != NULL && temp2->next->next != NULL) {
		temp1 = temp1->next;
		temp2 = temp2->next->next;
	}
	(*new_head) = temp1->next;
	temp1->next = NULL;
}