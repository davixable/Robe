#include <stdio.h>
#include <time.h>

int main () {
    int posizione_tartaruga=1;
    int posizione_lepre=1;
    int dice_roll1=0;
    int dice_roll2=0;
    int game_state=1;
    int a;
    srand(time(NULL));
    printf("La gara tra la tartaruga e la lepre sta per cominciare. Premi un tasto per partire!\n");
    getchar();
    printf("ALLE POSIZIONI....\nPARTENZA....\nVIA!!!!\n");

    do {
    while (posizione_tartaruga<70 && posizione_lepre<70) {
    dice_roll1= rand()%10 +1;
    dice_roll2= rand()%10 +1;
    switch (dice_roll1) {
        case 1: ... 5:
            posizione_tartaruga=posizione_tartaruga+3;
            break;
        case 6 ... 7:
            posizione_tartaruga=posizione_tartaruga-6;
            break;
        case 8 ... 10: 
            posizione_tartaruga=posizione_tartaruga+1;
            break;
    }

    switch (dice_roll2) {
        case 1 ... 2:
                break;
        case 3 ... 4:
            posizione_lepre=posizione_lepre+9;
            break;
        case 5: 
            posizione_lepre=posizione_lepre-12;
            break;
        case 6 ... 8:
            posizione_lepre=posizione_lepre+1;
            break;
        case 9 ... 10:
            posizione_lepre=posizione_lepre-2;
            break;
        
    }
    if (posizione_tartaruga<1) {
        posizione_tartaruga=1;
    }
    if (posizione_tartaruga>70) {
        posizione_tartaruga=70;
    }
    if (posizione_lepre<1) {
        posizione_lepre=1;
    }
    if (posizione_lepre>70) {
        posizione_lepre=70;
    }
        for (int i=0; i<=70;i++) {
            if (i==posizione_tartaruga && i==posizione_lepre) {
                printf("OUCH!!!");
                for (int j=i;j<=63;j++) {
                    printf(".");
                }
                break;
            }
            else if(posizione_tartaruga==i) {
                printf("T");
            }
            else if (posizione_lepre==i) {
                printf("L");
            }
            else {
                printf(".");
            }
            usleep(4500);
        }
        puts("");
    }

    puts("La gara e' terminata!!");
    if (posizione_tartaruga==posizione_lepre) {
        puts("E' un pareggio! Che gara incredibile!");
    }
    else if(posizione_tartaruga==70) {
        puts("La tartaruga ha vinto! Che gara emozionante!");
    }
    else if(posizione_lepre==70) {
        puts("La lepre ha vinto!Beh, c'era da aspettarselo..");
    }
    printf("Vuoi fare un'altra partita?\n");
    while(1) {
        printf("Digita 1 per ricominciare o 0 per terminare\n");
        scanf("%d", &game_state);
        if (game_state==0) {
            printf("Uscita dal gioco in corso...\n");
            break;
        }
        else if(game_state==1) {
            posizione_lepre=1;
            posizione_tartaruga=1;
            break;
        }
        else {
            printf("Scelta non valida.\n");
            continue;
        }
}
} while (game_state==1);
    return 0;
}