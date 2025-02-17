#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


char male_names[50][20] = {
    "Luca", "Marco", "Giovanni", "Matteo", "Alessandro", "Francesco", "Andrea", "Davide", "Simone", "Riccardo",
    "Gabriele", "Filippo", "Emanuele", "Stefano", "Daniele", "Giorgio", "Pietro", "Antonio", "Leonardo", "Paolo",
    "Vincenzo", "Roberto", "Salvatore", "Carlo", "Michele", "Domenico", "Federico", "Samuele", "Enrico", "Tommaso",
    "Edoardo", "Claudio", "Christian", "Alberto", "Angelo", "Massimo", "Fabio", "Alessio", "Manuel", "Diego",
    "Nicola", "Sergio", "Maurizio", "Giacomo", "Gustavo", "Fabrizio", "Raffaele", "Ivan", "Benedetto", "Valerio"
};

char female_names[50][20] = {
    "Maria", "Giulia", "Francesca", "Anna", "Martina", "Sara", "Laura", "Alessia", "Elena", "Silvia",
    "Camilla", "Valentina", "Marta", "Alice", "Federica", "Giorgia", "Chiara", "Simona", "Angela", "Clara",
    "Cristina", "Monica", "Beatrice", "Serena", "Vanessa", "Daniela", "Sonia", "Paola", "Rita", "Stefania",
    "Veronica", "Patrizia", "Ilaria", "Barbara", "Eleonora", "Aurora", "Elisa", "Benedetta", "Lucia", "Flavia",
    "Marina", "Nicole", "Rossella", "Irene", "Giovanna", "Carlotta", "Alessandra", "Nadia", "Renata", "Ester"
};

char last_names[100][20] = {
    "Rossi", "Russo", "Ferrari", "Esposito", "Bianchi", "Romano", "Colombo", "Ricci", "Marino", "Greco",
    "Bruno", "Gallo", "Conti", "De Luca", "Mancini", "Costa", "Giordano", "Rizzo", "Lombardi", "Moretti",
    "Barbieri", "Fontana", "Santoro", "Mariani", "Rinaldi", "Caruso", "Ferrara", "Galli", "Martini", "Leone",
    "Longo", "Gentile", "Martinelli", "Vitale", "Lombardo", "Serra", "Coppola", "De Santis", "D'Angelo", "Fiore",
    "Monti", "De Rosa", "Valentini", "Messina", "Fabbri", "Bianco", "Marchetti", "Parisi", "Villa", "Sanna",
    "Sala", "De Angelis", "Palumbo", "Pellegrini", "Gatti", "Bernardi", "Donati", "Piras", "Neri", "Grassi",
    "Farina", "Ruggiero", "Sorrentino", "Amato", "Mazza", "Orlando", "Brunetti", "De Simone", "Battaglia", "Pugliese",
    "Fiorelli", "Montanari", "D'Amico", "Ferrero", "De Vito", "Landi", "Locatelli", "Morelli", "Carbone", "Cattaneo",
    "Rossetti", "Silvestri", "Pagano", "D'Onofrio", "Testa", "Piazza", "Crispino", "Mattioli", "Riva", "Bellini",
    "Ghezzi", "Caruso", "Marchegiani", "Benvenuti", "Corsini", "Sartori", "Romagnoli", "Zanetti", "Palmieri", "Basili"
};


float randomFloatGrade();
void spawnStudents(int n);

float randomFloatGrade(){
    float grade= 2+0.5*(rand()%17);
    return grade;
}

void spawnStudents(int n){
    FILE *file=fopen("registro.txt","w");
    if (file==NULL){
        printf("Errore nell'apertura del file.");
        return;
   }
    fprintf(file, "%d",n);
    for (int i=0; i<n;i++){
        int gender =rand()%2; //0 = male , 1=female
        char student_gender;
        char name[20];
        char last_name[20];
        if (gender==0) {
            student_gender='M';
            strcpy(name, male_names[rand()%50]);
        } else{
            student_gender='F';
            strcpy(name, female_names[rand()%50]);
        }
        strcpy(last_name, last_names[rand()%100]);
        fprintf(file, "\n%d %s %s\n%d %c %.2f %.2f %.2f %.2f %.2f", i, name, last_name,
        rand()%10 +5, student_gender, randomFloatGrade(), randomFloatGrade(), randomFloatGrade(),
        randomFloatGrade(), randomFloatGrade());
   }
   fclose(file);
}

int main (){
    srand(time(NULL));
    int n;
    printf("Quanti alunni vuoi generare?\n");
    scanf("%d",&n);
    spawnStudents(n);
}
