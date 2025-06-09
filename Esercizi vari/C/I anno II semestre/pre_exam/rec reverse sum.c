/*
input : 10->20->30->40->50->60->70->80->90->100
output : 550->540->520->490->450->400->340->270->190->100
*/

typedef struct Node {
	int value;
	struct Node* next;
}Node;

Node* reverse_sum(Node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	Node* next = reverse_sum(head->next);
	head->value += next->value;
	return head;
}