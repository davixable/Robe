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

typedef struct {
    int ID, dob;
    char name[80], last_name[80];
} User;

User *add_user(User *list, int *user_num);
User *delete_user(User *list, int *user_num);
User *sort_list(User *list, int l, int r);
User *load_users(User *list, int *user_num);
int save_list(User *list, int *user_num);
void merge_list(User *list, int l, int m, int r);
void print_list(User *list, int *user_num);
void clear_buffer();


User *add_user(User *list, int *user_num){
    list = realloc(list, sizeof(User)*((*user_num)+1));
    if (list == NULL){
        printf("Errore di allocazione della lista.\n");
        exit(1);
    }
    User *user = &(list)[*user_num];

    user->ID = *user_num;

    printf("Inserisci nome utente: ");
    fgets(user->name, 80, stdin);
    user->name[strcspn(user->name, "\n")] = '\0';

    printf("Inserisci il cognome dell'utente: ");
    fgets(user->last_name, 80, stdin);
    user->last_name[strcspn(user->last_name, "\n")] = '\0';

    printf("Inserisci la data di nascita dell'utente in formato aaaammgg: ");
    scanf("%d", &user->dob);
    clear_buffer();

    (*user_num)++;
    printf("Utente aggiunto con successo!\n");
    return list;
}

User *delete_user(User *list, int *user_num){
    if (*user_num == 0){
        printf("Non ci sono utenti nella lista.");
        return list;
    }

    int ID = -1;
    print_list(list, user_num);
    printf("Inserisci l'ID dell'utente che vuoi cancellare (0 - %d): ", *user_num - 1);
    scanf("%d", &ID);

    int users = *user_num;
    for (int i = 0; i < users - 1; i++){
        if (i >= ID){
            list[i] = list[i+1];
            list[i].ID = i;
        }
    }

    printf("Utente cancellato con successo.\n");
    (*user_num)--;
    list = realloc(list, sizeof(User)*(*user_num));

    return list;
}

int save_list(User *list, int *user_num){
    FILE *fp = fopen("lista_utenti.bin", "wb");
    if (!fp){
        printf("Errore nella creazione del file.\n");
        return 0;
    }
    if (*user_num == 0){
        printf("Non sono presenti utenti nell'archivio.\n");
        return 0;
    }

    
    if (fwrite(user_num, sizeof(int), 1, fp) != 1) {
        printf("Errore nella scrittura del # di utenti.\n");
        fclose(fp);
        return 0;
    }

    if (fwrite(list, sizeof(User), *user_num, fp) != *user_num) {
        printf("Errore nella scrittura degli utenti.\n");
        fclose(fp);
        return 0;
    }
    fclose(fp);

    printf("Archivio salvato con successo.\n");
    return 1;

}

User *load_users(User *list, int *user_num) {
    FILE *fp = fopen("lista_utenti.bin", "rb");
    if (!fp) {
        printf("Errore apertura file in lettura.\n");
        return NULL;
    }
    
    if (fread(user_num, sizeof(int), 1, fp) != 1) {
        printf("Errore lettura numeri degli utenti.\n");
        fclose(fp);
        return NULL;
    }
    
    list = malloc(sizeof(User) * (*user_num));

    if (!list) {
        printf("Memoria insufficiente per creare l'archivio.\n");
        fclose(fp);
        return NULL;
    }
    
    if (fread(list, sizeof(User), *user_num, fp) != *user_num) {
        printf("Errore lettura utenti.\n");
        free(list);
        fclose(fp);
        return NULL;
    }
    
    fclose(fp);

    printf("Archivio caricato con successo.\n");
    return list;
}
void print_list(User *list, int *user_num){
    int users = *user_num;
    for (int i = 0; i < users; i++){
        User *user = &(list)[i];
        printf("ID: %d\t\tNome: %s\t\tCognome: %s\t\tData di nascita: %d", user->ID, user->name, user->last_name, user->dob);
        puts("");
    }
}

User *sort_list(User *list, int l, int r){
    if (l<r){
        int m = l+(r-l)/2;
        sort_list(list, l, m);
        sort_list(list, m+1, r);
        merge_list(list, l, m, r);
    }
    printf("Lista ordinata correttamente.\n");
    return list;
}

void merge_list(User *list, int l, int m, int r){
    int size1 = m-l+1;
    int size2 = r-m;

    User *arr1 = calloc(size1,sizeof(User));
    User *arr2 = calloc(size2,sizeof(User));

    for (int i = 0; i<size1;i++){
        arr1[i] = list[l+i];
    }

    for (int i=0; i<size2;i++){
        arr2[i] = list[m+i+1];
    }

    int i=0,j=0,k=l;

    while(i<size1 && j<size2){
        if(strcmp(arr1[i].last_name, arr2[j].last_name)<= 0){
            list[k] = arr1[i];
            i++;
        } else{
            list[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i<size1){
        list[k] = arr1[i];
        i++;
        k++;
    }

    while (j<size2){
        list[k] = arr2[j];
        j++;
        k++;
    }
    
    while (l<=r){
        list[l].ID=l;
        l++;
    }
    free(arr1);
    free(arr2);
}

void clear_buffer(){
    while (getchar()!= '\n');
}

int main (){
    User *list = NULL;
    int user_num = 0;
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
            case 0: free(list);
                    printf("Uscita in corso...\n");
                    return 0;        
            case 1: list = add_user(list, &user_num);
                    break;

            case 2: save_list(list, &user_num);
                    break;

            case 3: list = load_users(list, &user_num);
                    break;

            case 4: print_list(list, &user_num);
                    break;

            case 5: list = delete_user(list, &user_num);
                    break;

            case 6: list = sort_list(list, 0, user_num - 1);
                    break;

            default:
                    printf("Scelta non valida. Devi digitare un tasto da 0 a 6.\n");
                    break;
        }
    }
}