#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_NAME_LENGTH 40

int students_num=0;

typedef struct {
    float math, history, geography, italian, english;
} Grades;

typedef struct{
    int ID, age;
    char name[MAX_NAME_LENGTH], gender;
    Grades grades;
} Student;


void addStudent(Student **student);
void addGrades(Student *student);
void printIDs(Student **student);
void printInfo(Student **student);
void printSingleInfo(Student *student);
void deleteStudent(Student **student);
float getGrade();
int getID();
void clearBuffer();

void clearBuffer(){
    while (getchar() != '\n');
}

void addStudent(Student **students){
    *students=realloc(*students, (students_num+1) * sizeof(Student));
    if (*students == NULL) {
        printf("La tua memoria e' piena, non e' possibile aggiungere studenti.\n");
        exit(1);
    }
    Student *student=&(*students)[students_num];
    student->ID=students_num;
    printf("Inserisci nome studente:");
    fgets(student->name,MAX_NAME_LENGTH,stdin);
    student->name[strcspn(student->name, "\n")] = '\0';

    printf("Inserisci l'età dello studente:");
    scanf("%d", &student->age);
    clearBuffer();

    while (1){
        printf("Inserisci il sesso dello studente (M o F):");
        scanf("%c", &student->gender);
        clearBuffer();
        if (student->gender != 'M' && student->gender != 'F'){
            student->gender='X';
            printf("Scelta non valida.\n");
            continue;
        }
        break;
    }
    int choice;
    printf("Desideri inserire anche i voti?  (premi 1 per inserirli o un altro numero per tornare al menu')\n");
    scanf("%d", &choice);
    clearBuffer();
    if (choice==1){
        addGrades(student);
    }
    students_num++;
    printf("Studente aggiunto con successo!\n");
}

void addGrades(Student *student){
    printf("Matematica\t");
    student->grades.math=getGrade();

    printf("Storia\t\t");
    student->grades.history=getGrade();

    printf("Geografia\t");
    student->grades.geography=getGrade();

    printf("Italiano\t");
    student->grades.italian=getGrade();

    printf("Inglese\t\t");
    student->grades.english=getGrade();
}

float getGrade(){
    float grade=-1;
    while(grade == -1){
        printf("Inserisci il voto (0-10):");
        scanf("%f",&grade);
        clearBuffer();
        if (grade>=0 && grade<=10){
            break;
        } else{
            grade=-1;
            printf("Hai inserito un voto non valido. (min. 0 e max. 10)\n");
        }
    }
    return grade;
}

void printIDs(Student **student){
    for (int i=0;i<students_num;i++){
        printf("ID:%d\tNome:%s\n", (*student)[i].ID, (*student)[i].name);
    }
}

void printInfo(Student **students){
    for (int i=0;i<students_num;i++){
    printf("##########################################\n");
    printf("ID:%d\tNome:%s\tEta':%d\t\tSesso:%c\n", 
    (*students)[i].ID, (*students)[i].name, (*students)[i].age, (*students)[i].gender);
    printf("\n\t\t\tVOTI\t\t\t\n\n");
    printf("Matematica: %.2f\nStoria: %.2f\nGeografia: %.2f\nItaliano: %.2f\nInglese: %.2f\n", 
    (*students)[i].grades.math, (*students)[i].grades.history, (*students)[i].grades.geography,(*students)[i].grades.italian, (*students)[i].grades.english);
    float avg=((*students)[i].grades.math+(*students)[i].grades.history+(*students)[i].grades.geography+(*students)[i].grades.italian+(*students)[i].grades.english)/5;
    printf("\n%s ha la media del %.2f\n\n", (*students)[i].name, avg);
    }
}

void printSingleInfo(Student *student){
    printf("##########################################\n");
    printf("ID:%d\tNome:%s\tEta':%d\tSesso:%c\n", 
    student->ID, student->name, student->age, student->gender);
    printf("\n\t\t\tVOTI\t\t\t\n\n");
    printf("Matematica: %.2f\nStoria: %.2f\nGeografia: %.2f\nItaliano: %.2f\nInglese: %.2f\n", 
    student->grades.math, student->grades.history, student->grades.geography,student->grades.italian, student->grades.english);
    float avg=(student->grades.math+student->grades.history+student->grades.geography+student->grades.italian+student->grades.english)/5;
    printf("\n%s ha la media del %.2f\n\n", student->name, avg);

}

int getID(){
    int ID=-1;
    while (ID == -1){
        printf("Inserisci l'ID dello studente:");
        scanf("%d",&ID);
        clearBuffer();
        if(ID<0||ID>=students_num){
            ID=-1;
            printf("ID non valido. Inserisci un ID associato ad uno studente.\n");
            continue;
        }
        break;
    }
    return ID;
}

void deleteStudent(Student **students){
    if (students_num==0){
        printf("Non sono presenti studenti nel registro.\n");
        return;
    }
    printf("################\nMenu' di cancellazione dati.\n");
    printIDs(students);
    int ID=getID();
    for (int i=0;i<students_num-1;i++){
        if (i>=ID){
            (*students)[i]=(*students)[i+1];
            (*students)[i].ID=i;
        }
    }
    students_num--;
    *students = realloc(*students, students_num * sizeof(Student));
    printf("Studente eliminato con successo. Torno al menu' principale..\n");
}

int main (){
    Student *students=NULL;
    int choice,ID;
    printf("Benvenuti nel registro di classe.\n");
    while(1){
        printf("##########################################\n");
        printf("Cosa desideri fare?\nPremi:\n1. per aggiungere uno studente\n2. per modificare i voti\n3. per mostrare info studente");
        printf("\n4. per mostrare info di tutti gli studenti\n5. per eliminare i dati di uno studente\n6. per uscire\n");
        scanf("%d", &choice);
        clearBuffer();
        switch (choice){
        case 1:
            addStudent(&students);
            break;
        case 2: 
            printIDs(&students);
            ID=getID();
            printf("\n");
            addGrades(&students[ID]);
            break;
        case 3:
            printIDs(&students);
            ID=getID();
            printf("\n");
            printSingleInfo(&students[ID]);
            break;
        case 4:
            printInfo(&students);
            break;
        case 5:
            deleteStudent(&students);
            break;
        case 6:
            printf("Uscita in corso...\n");
            free(students);
            return 0;
        default:
            printf("Scelta non valida.\n");
        }
    }
}