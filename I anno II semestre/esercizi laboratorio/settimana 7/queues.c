#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int value;
    struct item *next;
} Queue;

void push(Queue **my_queue);
void pop(Queue **my_queue);
void print_queue(Queue *my_queue);

void push(Queue **my_queue){
    Queue *temp = malloc(sizeof(Queue));
    printf("Valore da aggiungere : ");
    scanf("%d", &temp->value);
    temp->next = NULL;
    if(*my_queue == NULL){
        *my_queue = temp;
        return;
    }
    Queue *curr = *my_queue;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
}

void pop(Queue **my_queue){
    if (*my_queue == NULL){
        printf("La coda e' vuota.\n");
        return;
    }
    Queue *temp = *my_queue;
    *my_queue = temp->next;
    printf("Valore estratto dalla coda: %d.\n", temp->value);
    free(temp);
}

void print_queue(Queue *my_queue){
    if (my_queue == NULL){
        printf("La coda e' vuota.\n");
        return;
    }
    while(my_queue){
        printf("%d -> ", my_queue->value);
        my_queue = my_queue->next;
    }
    printf("NULL\n");
}
int main(){
    Queue *my_queue = NULL;
    int choice = -1;
    while(1){
        printf("Cosa desideri fare?\n1. push item\n2. pop item\n3. print queue\n4. exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: push(&my_queue);
                break;
            case 2: pop(&my_queue);
                break;
            case 3: print_queue(my_queue);
                break;
            case 4: //exit
                break;
            default:
                break;
        }
    }
}