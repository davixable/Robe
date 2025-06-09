/*
data una lista, creare una bilista con i valori non multipli della lista.
*/

typedef struct Node {
	int value;
	struct Node* next;
}Node;

typedef struct BNode {
	int value;
	struct BNode* prev;
	struct BNode* next;

}BNode;


BNode* clear_blist(Node* head, BNode* Bhead) {
	if (head == NULL) {
		return Bhead;
	}
	BNode* new_node = malloc(sizeof(BNode));
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->value = head->value;
	if (Bhead == NULL) {
		Bhead = new_node;
	}
	else {
		BNode* curr = Bhead;
		BNode* prec = NULL;
		while (curr) {
			if (new_node->value % curr->value == 0 || curr->value % new_node->value == 0) {
				return clear_blist(head->next, Bhead);
			}
			prec = curr;
			curr = curr->next;
		}
		prec->next = new_node;
		new_node->prev = prec;
	}
	return clear_blist(head->next, Bhead);
}