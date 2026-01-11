#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent();
void displayAll();
void searchStudent();
void deleteStudent();
void updateStudent();

int main() {
    int choice;
    
    printf("\n*** STUDENT MANAGEMENT SYSTEM ***\n");
    
    while(1) {
        printf("\n1. Add Student\n");
        printf("2. Display All\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Update Student\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void addStudent() {
    struct Student s;
    FILE *fp;
    
    printf("\nEnter Roll No: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    
    fp = fopen("student.dat", "ab");
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    
    printf("Student added!\n");
}

void displayAll() {
    struct Student s;
    FILE *fp;
    
    fp = fopen("student.dat", "rb");
    if(fp == NULL) {
        printf("No records!\n");
        return;
    }
    
    printf("\nRoll\tName\t\tMarks\n");
    printf("--------------------------------\n");
    
    while(fread(&s, sizeof(s), 1, fp)) {
        printf("%d\t%s\t\t%.2f\n", s.roll, s.name, s.marks);
    }
    
    fclose(fp);
}

void searchStudent() {
    struct Student s;
    FILE *fp;
    int roll, found = 0;
    
    printf("\nEnter Roll No to search: ");
    scanf("%d", &roll);
    
    fp = fopen("student.dat", "rb");
    if(fp == NULL) {
        printf("No records!\n");
        return;
    }
    
    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.roll == roll) {
            printf("\nRoll: %d\n", s.roll);
            printf("Name: %s\n", s.name);
            printf("Marks: %.2f\n", s.marks);
            found = 1;
            break;
        }
    }
    
    if(!found) printf("Student not found!\n");
    fclose(fp);
}

void deleteStudent() {
    struct Student s;
    FILE *fp, *temp;
    int roll, found = 0;
    
    printf("\nEnter Roll No to delete: ");
    scanf("%d", &roll);
    
    fp = fopen("student.dat", "rb");
    temp = fopen("temp.dat", "wb");
    
    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.roll == roll) {
            found = 1;
        } else {
            fwrite(&s, sizeof(s), 1, temp);
        }
    }
    
    fclose(fp);
    fclose(temp);
    
    remove("student.dat");
    rename("temp.dat", "student.dat");
    
    if(found) printf("Student deleted!\n");
    else printf("Student not found!\n");
}

void updateStudent() {
    struct Student s;
    FILE *fp, *temp;
    int roll, found = 0;
    
    printf("\nEnter Roll No to update: ");
    scanf("%d", &roll);
    
    fp = fopen("student.dat", "rb");
    temp = fopen("temp.dat", "wb");
    
    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.roll == roll) {
            printf("Enter new Name: ");
            scanf("%s", s.name);
            printf("Enter new Marks: ");
            scanf("%f", &s.marks);
            found = 1;
        }
        fwrite(&s, sizeof(s), 1, temp);
    }
    
    fclose(fp);
    fclose(temp);
    
    remove("student.dat");
    rename("temp.dat", "student.dat");
    
    if(found) printf("Student updated!\n");
    else printf("Student not found!\n");
}
