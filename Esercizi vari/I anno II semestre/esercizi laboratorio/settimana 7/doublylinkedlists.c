#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
    struct Node *prev;
}Node;

Node *add_tail(Node *head);
Node *delete_node(Node *head);
Node *insert_node(Node *head);
void print_list(Node *head);

Node *add_tail(Node *head){
    Node *temp = malloc(sizeof(Node));
    temp->next = NULL;
    temp->prev = NULL;
    printf("Inserisci il valore: ");
    scanf("%d", &temp->value);
    if(!head){
        head = temp;
    } else{
        Node *curr = malloc(sizeof(Node));
        curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
    curr->next = temp;
    temp->prev = curr;
    }

    return head;

}

void print_list(Node *head){
    if (!head){
        printf("La lista e' vuota.\n");
        return;
    }
    Node *curr = malloc(sizeof(Node));
    curr = head;
    while(head){
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

Node *delete_node(Node *head){
    if(!head){
        printf("La lista e' vuota.\n");
        return head;
    }
    print_list(head);
    int value = -1;
    printf("Quale valore vuoi eliminare?\n");
    scanf("%d", &value);

    Node *temp = head;
    if(head->value == value){
        Node *temp = head->next;
        temp->prev = NULL;
        free(head);
        return temp;
    }

    while(temp && temp->value != value){
        temp = temp->next;
    }
    if (!temp){
        printf("Valore %d non trovato.\n", value);
        return head;
    }

    temp->prev->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}

Node *insert_node(Node *head){
    if(!head){
        head = add_tail(head);
        return head;
    }
    int value = -1;
    printf("Inserisci valore: ");
    scanf("%d", &value);
    
    Node *curr = head;
    while(curr && curr->value>value){
        curr = curr->next;
    }
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->prev = curr;
    if(curr->next != NULL){
        new_node->next = curr->next;
    }
    curr->next = new_node;
    return head;
}
Node *exit_list(Node *head){
    if(!head){
        return head;
    }
    Node *curr = malloc(sizeof(Node));

}
int main (){
    Node *head = NULL;
    int choice = -1;
    while(1){
        printf("Cosa desideri fare?\n1. add tail\n2. print list\n3. delete node\n4. insert node\n5. exit\n");
        scanf("%d", &choice);
        switch (choice){
            case 1: head = add_tail(head);
                    break;
            case 2: print_list(head);
                    break;
            case 3: head = delete_node(head);
                    break;
            case 4: head = insert_node(head);
                    break;
            case 5: // head = delete_list(head);
                    free(head);
                    printf("Uscita in corso...\n");
                    return 0;
                    break;
            default:
                    break;
        }
    }
}