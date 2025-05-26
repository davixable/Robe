#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

Node *create_list(int number_of_nodes);
void print_list(Node *head);
int count_elements_in_list(Node *head);

Node *create_list(int number_of_nodes){
    Node *head = NULL, *current = NULL;

    for (int i = 0; i < number_of_nodes; i++){
        Node *new_node = malloc(sizeof(Node));
        if (!new_node){
            printf("Memoria insufficiente.\n");
            return head;
        }

        printf("Inserisci il valore #%d: ", i);
        scanf("%d", &new_node->value);
        new_node->next = NULL;

        if (!head){
            head = new_node;
            current = head;
        } else{
            current->next = new_node;
            current = new_node;
        }
    }
    return head;
}

void print_list(Node *head){
    if(!head){
        printf("La lista e' vuota. \n");
        return;
    }
    Node *current = head;
    while (current){
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int count_elements_in_list(Node *head){
    if(!head){
        printf("La lista e' vuota.\n");
        return 0;
    }

    Node *current = head;
    int count = 0;

    while(current){
        count++;
        current=current->next;
    }
    return count;
}
int main (){
    int nodes_number;
    printf("Inserisci numero di nodi della lista: \n");
    scanf("%d", &nodes_number);
    Node *lista = create_list(nodes_number);
    printf("Stampa della lista:\n");
    print_list(lista);
    int number_of_elements = count_elements_in_list(lista);
    printf("Gli elementi della lista sono: %d.\n", number_of_elements);
}