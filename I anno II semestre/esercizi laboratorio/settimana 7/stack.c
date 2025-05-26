#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int value;
    struct item *next;
} Stack;

void push(Stack **my_stack);
void pop(Stack **my_stack);
void peek(Stack *my_stack);

void push(Stack **my_stack){
    int value;
    printf("Valore da inserire: ");
    scanf("%d", &value);

    Stack *temp = malloc(sizeof(Stack));
    temp->value = value;
    if (*my_stack == NULL){
        temp->next == NULL;
        *my_stack = temp;
        return;
    }

    temp->next = *my_stack;
    *my_stack = temp;
}

void pop(Stack **my_stack){
    if (*my_stack == NULL){
        printf("Lo stack e' vuoto.\n");
        return;
    }
    int value;
    Stack *temp = *my_stack;
    *my_stack = temp->next;
    value = temp->value;
    printf("Valore estratto dallo stack: %d.\n", value);
    free(temp);

}

void peek(Stack *my_stack){
    if(my_stack == NULL){
        printf("Lo stack e' vuoto.\n");
        return;
    }
    Stack *temp = my_stack;
    while(temp){
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    Stack *my_stack = NULL;
    int choice = -1;
    while(1){
        printf("Cosa vuoi fare?\n1. push item\n2. pop item\n3. peek\n4. exit");
        scanf("%d", &choice);
        switch (choice){
            case 1: push(&my_stack);
                break;
            case 2: pop(&my_stack);
                break;
            case 3: peek(my_stack);
                break;
            case 4: //exit
                break;
            default:
                break;
        }
    }
}