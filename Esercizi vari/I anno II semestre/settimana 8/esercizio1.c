/* Si realizzi un programma che attraverso un menù e opportune funzioni gestisca una lista concatenata bilaterale.

Le voci di Menù sono:

Voce di Menù 0 :Chiusura del programma effettuando la deallocazione della lista
Voce di menù 1: Inserimento in Testa di un nuovo nodo
Voce di Menù 2: Inserimento in Coda di un nuovo nodo
Voce di Menù 3: Inserimento in  una determinata posizione partendo dalla  Testa
Voce di Menù 4: Inserimento in  una determinata posizione partendo dalla  Coda
Voce di Menù 5: Visualizzazione della lista dalla Testa
Voce di Menù 6: Visualizzazione della lista dalla Coda

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *prev;
    struct Node *next;
}Node;

Node *free_list(Node *head);
Node *add_head(Node *head);
Node *add_tail(Node *head);
Node *insert_from_head(Node *head);
Node *insert_from_tail(Node *head);
void print_list_from_head(Node *head);
void print_list_from_tail(Node *head);

Node *free_list(Node *head){
    if(!head){
        return head;
    }
    Node *curr=head;
    Node *prev=NULL;
    while(curr->next !=NULL){
        prev=curr;
        curr=curr->next;
        free(prev);
    }
    return head;
}

Node *add_head(Node *head){
    Node *new_node = malloc(sizeof(Node));
    printf("Inserisci valore: ");
    scanf("%d", &new_node->value);
    if(!head){
        new_node->prev=NULL;
        new_node->next=NULL;
        return new_node;
    } else{
        new_node->next=head;
        new_node->prev=NULL;
        head->prev=new_node;
        return new_node;
    }
}

Node *add_tail(Node *head){
    Node *new_node=malloc(sizeof(Node));
    printf("Inserisci valore: ");
    scanf("%d", &new_node->value);

    if(!head){
        new_node->prev=NULL;
        new_node->next=NULL;
        return new_node;
    } else{
        Node *curr=head;
        while(curr->next != NULL){
            curr=curr->next;
        }
        curr->next=new_node;
        new_node->prev=curr;
        new_node->next=NULL;
        return head;
    }
}

Node *insert_from_head(Node *head){
    Node *new_node=malloc(sizeof(Node));
    printf("Inserisci valore: ");
    scanf("%d", &new_node->value);
    if(!head){
        new_node->prev=NULL;
        new_node->next=NULL;
        return new_node;
    } else{
        Node *curr=head;
        Node *prev=NULL;
        while(curr!=NULL && new_node->value >= curr->value){
            prev=curr;
            curr = curr->next;
        }
        
        if(!prev){
            new_node->prev=NULL;
            new_node->next=head;
            head->prev=new_node;
            return new_node;
        }
        new_node->prev=prev;
        prev->next=new_node;
        if(curr){
            new_node->next=curr;
            curr->prev=new_node;
        } else{
            new_node->next=NULL;
        }
    }
    return head;
}

Node *insert_from_tail(Node *head){
    Node *new_node=malloc(sizeof(Node));
    printf("Inserisci valore: ");
    scanf("%d", &new_node->value);
    if(!head){
        new_node->prev=NULL;
        new_node->next=NULL;
        return new_node;
    }

    Node *curr=head;
    Node *prev=NULL;
    while(curr->next!=NULL){
        prev=curr;
        curr=curr->next;
    }
    if(curr->value<=new_node->value){
        curr->next=new_node;
        new_node->prev=curr;
        new_node->next=NULL;
        return head;
    }

    while(prev && new_node->value<prev->value){
        curr=prev;
        prev=prev->prev;
    }
    if(!prev){
        new_node->prev=NULL;
        new_node->next=curr;
        curr->prev=new_node;
        return new_node;
    } else{
        prev->next=new_node;
        curr->prev=new_node;
        new_node->prev=prev;
        new_node->next=curr;
    }
    return head;
}

void print_list_from_head(Node *head){
    if(!head){
        printf("La lista e' vuota.\n");
        return;
    }
    while(head){
        printf(" <-%d-> ", head->value);
        head=head->next;
    }
    puts("");
}

void print_list_from_tail(Node *head){
    if(!head){
        printf("La lista e' vuota.\n");
        return;
    }
    Node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    while(curr){
        printf(" <-%d-> ", curr->value);
        curr=curr->prev;
    }
}

int main (){
    Node *head=NULL;
    int choice;
    while(1){
        printf("\nCosa desideri fare?\n0)Chiudi il programma.\n1)Aggiungi un nodo in testa.\n2)Aggiungi un nodo in coda.\n3)Insert dalla testa.\n"
               "4)Insert dalla coda.\n5)Stampa lista dalla testa.\n6)Stampa lista dalla coda.\n");
        if(scanf("%d", &choice) != 1){
            while(getchar()!=('\n'));
            printf("Devi inserire un numero (0-8).\n");
            continue;
        }
        switch(choice){
            case 0: head=free_list(head);
                    return 0;
            case 1: head = add_head(head);
                break;
            case 2: head= add_tail(head);
                break;
            case 3: head=insert_from_head(head);
                break;
            case 4: head=insert_from_tail(head);
                break;
            case 5: print_list_from_head(head);
                break;
            case 6: print_list_from_tail(head);
                break;
            default: 
                break;
        }
    }
}