
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNo;
    char grade;
    char branch[50];
};

void writeStudentRecordsToFile() {
    FILE *file;
    struct Student student;

    file = fopen("student_records.txt", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    for (int i = 0; i < numStudents; i++) {
        printf("Enter student #%d details:\n", i + 1);
        printf("Name: ");
        scanf("%s", student.name);
        printf("Roll No: ");
        scanf("%d", &student.rollNo);
        printf("Grade: ");
        scanf(" %c", &student.grade); // Notice the space before %c to consume newline
        printf("Branch: ");
        scanf("%s", student.branch);

        fprintf(file, "%s %d %c %s\n", student.name, student.rollNo, student.grade, student.branch);
    }

    fclose(file);
    printf("Student records have been written to student_records.txt.\n");
}

void readAndStoreStudentRecordsByBranch() {
    FILE *file;
    struct Student student;

    file = fopen("student_records.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    while (fscanf(file, "%s %d %c %s", student.name, &student.rollNo, &student.grade, student.branch) != EOF) {
        char branchFileName[100];
        sprintf(branchFileName, "%s_records.txt", student.branch);

        FILE *branchFile = fopen(branchFileName, "a");
        if (branchFile == NULL) {
            printf("Error opening branch file for %s.\n", student.branch);
            continue;
        }

        fprintf(branchFile, "%s %d %c %s\n", student.name, student.rollNo, student.grade, student.branch);
        fclose(branchFile);
    }

    fclose(file);
    printf("Student records have been stored branch-wise in separate files.\n");
}

int main8() {
    writeStudentRecordsToFile();
    readAndStoreStudentRecordsByBranch();

    return 0;
}
