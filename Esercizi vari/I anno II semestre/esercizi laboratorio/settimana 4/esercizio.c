/*

GESTIONE ARCHIVIO UTENTI

Realizzare un programma che attraverso un menù e opportune funzioni:

Voce di Menù 0: Chiuda il programma effettuando la deallocazione della lista (?) ;

Voce di Menù 1: Richieda l'inserimento di nome utenti come stringhe di lunghezza al più 80, e le memorizzi 
dinamicamente in una lista di stringhe fino a quanto non viene immessa la stringa STOP (essa non viene quindi memorizzata) ;

Voce di Menù 2: Richeda il salvataggio su file della lista di utenti una riga per volta ;

Voce di Menù 3: Richieda il caricamento della lista dal file ;

Voce di Menù 4: Stampi tutti gli utenti della lista ;

Voce di Menù 5: Richieda la cancellazione di un utente nella lista ;

Voce di Menù 6: Richieda l'ordinamento lessicale degli utenti ;

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 80

int users_num = 0;

void clear_buffer();
void close_program(char ***users_list);
void add_user(char ***users_list);
void save_list(char **users_list);
void load_list(char ***users_list);
void print_list(char **users_list);
void delete_user(char ***users_list);
void sort_list(char **users_list);

void clear_buffer(){
    while (getchar() != '\n');
}

void close_program(char ***users_list) { 
    if (*users_list != NULL) {
        for (int i = 0; i < users_num; i++) {
            free((*users_list)[i]); 
        }
        free(*users_list);
        *users_list = NULL; 
    }
    exit(0);
}

void add_user(char ***users_list){
    while(1){
        char temp[MAX_NAME_LENGTH];
        printf("\nInserisci il nome dell'utente (STOP PER TERMINARE): ");
        fgets(temp, MAX_NAME_LENGTH, stdin);
        temp[strcspn(temp, "\n")] = '\0';
        if(strcmp(temp, "STOP") == 0 || strcmp(temp, "stop") == 0){
            printf("\nTorno al menu' ...\n");
            break;
        }

        *users_list = realloc(*users_list, (users_num+1) * sizeof(char*));
        (*users_list)[users_num] = malloc(MAX_NAME_LENGTH * sizeof(char));
        strcpy((*users_list)[users_num], temp);
        users_num++;
    }
}

void save_list(char **users_list){
    FILE *file = fopen("lista_utenti.txt", "w");
    if (file == NULL) {
        printf("\nErrore nella creazione del file.\n");
        return;
    }

    fprintf(file, "%d\n", users_num);
    for (int i = 0; i < users_num; i++){
        fprintf(file, "%s\n", users_list[i]);
    }

    fclose(file);
    printf("\nLista di utenti salvata correttamente.\n");
}

void load_list(char ***users_list){
    FILE *file = fopen("lista_utenti.txt", "r");
    if (file == NULL) {
        printf("\nErrore nel caricamento del file.\n");
        return;
    }
    fscanf(file, "%d\n", &users_num);
    *users_list = malloc(users_num * sizeof(char*));
    for (int i = 0; i < users_num; i++){
        (*users_list)[i] = malloc(MAX_NAME_LENGTH*sizeof(char));
        fscanf(file, "%s\n", (*users_list)[i]);
    }

    printf("\nLista di utenti caricata con successo.\n");
    fclose(file);
}

void print_list(char **users_list){
    printf("\nLista degli utenti: \n");
    for (int i = 0; i < users_num; i++){
        printf("Utente %d: %s\n", i, users_list[i]);
    }
}

void delete_user(char ***users_list){
    int choice = -1;
    print_list(*users_list);
    printf("\nInserisci il numero dell'utente che vuoi eliminare: ");
    scanf("%d", &choice);
    clear_buffer();

    free((*users_list)[choice]);
    for (int i = 0; i < users_num - 1; i++){
        if(i >= choice){
            strcpy((*users_list)[i], (*users_list)[i+1]);
        }
    }
    users_num--;
    *users_list = realloc(*users_list, (users_num-1) * sizeof(char*));
}

void sort_list(char **users_list){
    for (int i = 0; i < users_num - 1; i++){
        for (int j = 0; j < users_num - 1 - i; j++){
            if(strcmp(users_list[j], users_list[j+1]) > 0){
                char temp[MAX_NAME_LENGTH];
                strcpy(temp, users_list[j+1]);
                strcpy(users_list[j+1], users_list[j]);
                strcpy(users_list[j], temp);
            }
        }
    }
    printf("\nLista ordinata correttamente.\n");
}

int main(){
    char **users_list = NULL;
    int choice = -1;

    while(1){
        printf(
            "\n###########################\n"
            "Gestione archivio utenti: che operazione vuoi effettuare? Premi:\n"
            "0)Per chiudere il programma.\n"
            "1)Per aggiungere un utente.\n"
            "2)Per salvare la lista.\n"
            "3)Per caricare una lista esistente.\n"
            "4)Per stampare la lista.\n"
            "5)Per eliminare un utente\n"
            "6)Per ordinare la lista.\n"
            );
        scanf("%d", &choice);
        clear_buffer();
        switch (choice){
            case 0:
                    close_program(&users_list);
                    break;
            case 1:
                    add_user(&users_list);
                    break;
            case 2:
                    save_list(users_list);
                    break;
            case 3:
                    load_list(&users_list);
                    break;
            case 4:
                    print_list(users_list);
                    break;
            case 5:
                    delete_user(&users_list);
                    break;
            case 6:
                    sort_list(users_list);
                    break;
            default:
            printf("\nScelta non valida.\n");
        }
    }
}

