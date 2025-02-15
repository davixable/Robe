#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
#define MAX_LENGTH_NAME 40

int students_num=0;

typedef struct {
    float math;
    float history;
    float geography;
    float italian;
    float english;
} Grades;

typedef struct{
    int ID;
    int age;
    char name[MAX_LENGTH_NAME];
    char gender;
    Grades grades;
} Student;

void addStudent(Student *student);
void addGrades(Student *student);
void printIDs(Student *student);
void printInfo(Student *student);
float getGrade();
int getID();

void addStudent(Student *student){
    student->ID=students_num;
    printf("Inserisci nome studente:");
    fgets(student->name,MAX_LENGTH_NAME,stdin);
    student->name[strcspn(student->name, "\n")] = '\0';

    printf("Inserisci l'età dello studente:");
    scanf("%d", &student->age);
    while (getchar() != '\n');

    while (1){
        printf("Inserisci il sesso dello studente (M o F):");
        scanf("%c", &student->gender);
        while (getchar() != '\n');
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
    if (choice==1){
        addGrades(student);
    }
}

void addGrades(Student *student){
    printf("Inserisci il voto di matematica (0-10):");
    student->grades.math=getGrade();

    printf("Inserisci il voto di storia (0-10):");
    student->grades.history=getGrade();

    printf("Inserisci il voto di geografia (0-10):");
    student->grades.geography=getGrade();

    printf("Inserisci il voto di italiano (0-10):");
    student->grades.italian=getGrade();

    printf("Inserisci il voto di inglese (0-10):");
    student->grades.english=getGrade();
}

float getGrade(){
    float grade=-1;
    while(grade<0 || grade >10){
        grade=-1;
        printf("Inserisci il voto:");
        scanf("%f",&grade);
        if (grade>=0 && grade<=10){
            break;
        } else{
            printf("Hai inserito un voto non valido. (min. 0 e max. 10)");
        }
    }
    return grade;
}

void printIDs(Student *student){
   printf("ID:%d\tNome:%s\n", student->ID, student->name);
}

void printInfo(Student *student){
    printf("##########################################\n");
    printf("ID:%d\tNome:%s\tEta':%d\tSesso:%c\n", student->ID, student->name, student->age, student->gender);
    printf("\n\t\t\tVOTI\t\t\t\n\n");
    printf("Matematica:%.2f\nStoria:%.2f\nGeografia:%.2f\nItaliano:%.2f\nInglese:%.2f\n", student->grades.math, student->grades.history, student->grades.geography, student->grades.italian, student->grades.english);
    float avg=(student->grades.math+student->grades.history+student->grades.geography+student->grades.italian+student->grades.english)/5;
    printf("\n%s ha la media del %.2f.\n\n", student->name, avg);
}

int getID(){
    int ID=-1;
    while (1){
        printf("Inserisci l'ID dello studente:");
        scanf("%d",&ID);
        if(ID<0||ID>=students_num){
            printf("ID non valido. Inserisci un ID associato ad uno studente.\n");
            continue;
        }
        break;
    }
    return ID;
}

int main (){
    Student students[MAX_STUDENTS];
    int choice,ID;
    printf("Benvenuti nel registro di classe.\n");
    while(1){
        printf("##########################################\n");
        printf("Cosa desideri fare?\nPremi 1 per aggiungere uno studente, 2 per modificare i voti, 3 per mostrare info studente, 4 per mostrare info di tutti gli studenti o 5 per uscire.\n");
        scanf("%d", &choice);
        while (getchar() != '\n');
        switch (choice){
            case 1: 
                if(students_num==MAX_STUDENTS){
                printf("Limite di studenti raggiunto.\n");
                break;
                }
                    addStudent(&students[students_num]);
                    students_num++;
                    break;
            case 2: 
                for (int i=0;i<MAX_STUDENTS;i++){
                    if(i>=students_num){
                        break;
                    }
                    printIDs(&students[i]);
                }
                ID=getID();
                printf("\n");
                addGrades(&students[ID]);
                break;
            case 3:
                for (int i=0;i<MAX_STUDENTS;i++){
                    if(i>=students_num){
                        break;
                    }
                    printIDs(&students[i]);
                }
                ID=getID();
                printf("\n");
                printInfo(&students[ID]);
                break;
            case 4:
                for (int i=0;i<MAX_STUDENTS;i++){
                    if(i>=students_num){
                        break;
                    }
                    printInfo(&students[i]);
                }
                break;
            case 5:
                printf("Uscita in corso...\n");
                return 0;
            default:
                printf("Scelta non valida.\n");
        }
    }
}