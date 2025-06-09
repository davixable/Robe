/*
funzione che, data una lista in ingresso, restituisce una lista uguale alla prima ma senza duplicati
*/

typedef struct Node {
	int value;
	struct Node* next;
}Node;


Node* clear_list(Node* head, Node* new_head) {
	if (head == NULL) {
		return new_head;
	}
	Node* new_node = malloc(sizeof(Node));
	new_node->next = NULL;
	new_node->value = head->value;
	if (new_head == NULL) {
		new_head = new_node;
	}
	else {
		Node* curr = new_head;
		while (curr) {
			if (curr->value == new_node->value) {
				return clear_list(head->next, new_head);
			}
			if (curr->next == NULL) {
				curr->next = new_node;
				break;
			}
			curr = curr->next;
		}
	}
	return clear_list(head->next, new_head);
}