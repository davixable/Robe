/*

GESTIONE ARCHIVIO UTENTI

Realizzare un programma che attraverso un menù e opportune funzioni:

Voce di Menù 0: Chiuda il programma effettuando la deallocazione della lista ;

Voce di Menù 1: Richieda l'inserimento delle informazioni degli utenti in una struttura i cui campi sono ID identificatore
unico di tipo intero progressivo, Nome di tipo stringa max 80, Cognome di tipo stringa max 80, data di nascita di tipo intero
(ad esempio 19620115 sta per 15 gennaio 1962) ;

Voce di Menù 2: Richieda il salvataggio su un file binario della lista di utenti con in testa il numero di utenti salvati ;

Voce di Menù 3: Richieda il caricamento della lista dal file ;

Voce di Menù 4: Stampi tutti gli utenti della lista ;

Voce di Menù 5: Richieda la cancellazione di un utente di un dato ID ;

Voce di Menù 6: Richieda l'ordinamento lessicografico degli utenti per Cognome ;

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User{
    int ID, dob;
    char name[80], last_name[80];
    struct User *next;
}User;

User *add_user(User *head, int *users_num);
User *free_list(User *head);
User *delete_user(User *head, int *users_num);
User *load_list(User *head, int *users_num);
void print_list(User *head, int users_num);
void save_list(User *head, int user_num);
void clear_buffer();



User *add_user(User *list, int *users_num){
    User *head = list, *current = NULL;
    User *new_user = malloc(sizeof(User));

    if (!new_user){
        printf("Memoria insufficiente.\n");
        return head;
    }

    new_user->ID = *(users_num);
    printf("Inserisci nome utente: ");
    fgets(new_user->name, 80, stdin);
    new_user->name[strcspn(new_user->name, "\n")] = '\0';
    printf("Inserisci il cognome dell'utente: ");
    fgets(new_user->last_name, 80, stdin);
    new_user->last_name[strcspn(new_user->last_name, "\n")] = '\0';
    printf("Inserisci la data di nascita dell'utente in formato aaaammgg: ");
    scanf("%d", &new_user->dob);
    clear_buffer();

    new_user->next = NULL;
    if(!head){
        head = new_user;
    } 
    else{
        current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_user;
    }
    (*users_num)++;
    
    return head;
}

User *free_list(User *head){
    if (!head){
        return NULL;
    }
    while (head){
        struct User* temp = head->next;
        free(head);
        head = temp;
    }
    return NULL;
}

User *delete_user(User *head, int *users_num){
    if(!head){
        printf("La lista e' vuota.\n");
        return head;
    }

    int ID = -1;
    print_list(head, *(users_num));
    printf("Digita l'ID dell'utente che vuoi cancellare: ");
    scanf("%d", &ID);

    User *temp = head, *prev = NULL;
    if(head->ID == ID){
        head = temp->next;
        free(temp);
        *(users_num)--;
        return head;
    }

    while(temp != NULL && temp->ID != ID){
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("Utente con ID %d non trovato.\n", ID);
        return head;
    }

    prev->next = temp->next;
    free(temp);
    *(users_num)--;
    return head;
    
}

void print_list(User *head, int users_num){
    if (users_num == 0){
        printf("La lista e' vuota.\n");
        return;
    }
    User *current = head;
    while (current){
        printf("ID: %d\t\tNome: %s\t\tCognome: %s\t\tData di nascita: %d", current->ID, current->name, current->last_name, current->dob);
        current = current->next;
        puts("");
    }
}


void save_list(User *head, int users_num){

    if (users_num == 0){
        printf("Non sono presenti utenti nell'archivio.\n");
        return;
    }

    FILE *fp = fopen("lista_utenti.bin", "wb");
    if (!fp){
        printf("Errore nella creazione del file.\n");
        return;
    }

    if (fwrite(users_num, sizeof(int), 1, fp) != 1) {
        printf("Errore nella scrittura del # di utenti.\n");
        fclose(fp);
        return;     
    }

    User *current = head;
    while(current){
        if(fwrite(current, sizeof(User), 1, fp) == 1){
        current = current->next;
        } else{
            printf("Errore durante il salvataggio dell'archivio. \n");
            return;
        }
    }
    fclose(fp);
    printf("Archivio salvato con successo.\n");
}

User *load_list(User *head, int *users_num){
    FILE *fp = fopen("lista_utenti.bin", "rb");
    if (!fp) {
        printf("Errore apertura file in lettura.\n");
        return NULL;
    }
    
    if (fread(users_num, sizeof(int), 1, fp) != 1) {
        printf("Errore lettura numeri degli utenti.\n");
        fclose(fp);
        return NULL;
    }

    User *temp, *current;
    
    if (fread(head, sizeof(User), *users_num, fp) != *users_num) {
        printf("Errore lettura utenti.\n");
        free(head);
        fclose(fp);
        return NULL;
    }
    
    fclose(fp);

    printf("Archivio caricato con successo.\n");
    return head;
}

void clear_buffer(){
    while (getchar()!= '\n');
}

int main(){
    User *list = NULL;
    int users_num = 0;
    int choice = -1;

    while(1){
        printf( 
            "\n################################################################################################\n"
                "Menu' gestione archivio utenti. Quale operazione desideri effettuare?\n"
                "0. chiudi il programma\n1. aggiungi un utente\n2. salva l'archivio\n3. importa un archivio\n"
                "4. stampa gli utenti della lista.\n5. cancella un utente\n6. ordina la lista per cognome.\n"
            );
        scanf("%d", &choice);
        clear_buffer();
        switch(choice){
            case 0: list = free_list(list);
                    free(list);
                    printf("Uscita in corso...\n");
                    return 0;        
            case 1: list = add_user(list, &users_num);
                    break;

            case 2: save_list(list, users_num);
                    break;

            case 3: list = load_list(list, &users_num);
                    break;

            case 4: print_list(list, users_num);
                    break;

            case 5: list = delete_user(list, &users_num);
                    break;

            case 6: //sort list
                    break;

            default:
                    printf("Scelta non valida. Devi digitare un tasto da 0 a 6.\n");
                    break;
        }
    }
}
