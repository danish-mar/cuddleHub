#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Defining student structure: name, rollNo, Stream
struct StudentInfo {
    int rollNo;
    char name[40];
    char stream[40];
};

// Creating an array of student objects
struct StudentInfo Students[3];
static int currentStudent = 0; // Current number of students

// Function to search for a student by name
void SearchStudent() {
    char askStudentName[40];
    printf("\n[?] Enter Student Name: ");
    scanf("%s", askStudentName);

    int found = 0;

    for (int k = 0; k < currentStudent; k++) {
        if (strcmp(askStudentName, Students[k].name) == 0) {
            printf("\n------Student %i------", k);
            printf("\nName   : %s", Students[k].name);
            printf("\nRoll No: %i", Students[k].rollNo);
            printf("\nStream : %s", Students[k].stream);
            found = 1;
        }
    }

    if (!found) {
        printf("\n[!] Student Not found");
    }
}

// Function to print all students
void PrintStudents() {
    if (currentStudent == 0) {
        printf("\n[!] No students to display.");
        return;
    }

    for (int j = 0; j < currentStudent; j++) {
        printf("\n------Student %i------", j);
        printf("\nName   : %s", Students[j].name);
        printf("\nRoll No: %i", Students[j].rollNo);
        printf("\nStream : %s", Students[j].stream);
    }
}

// Function to add a student
void AddStudent() {
    if (currentStudent >= 3) {
        printf("\n[!] Maximum number of students reached.");
        return;
    }

    printf("\n[i] Entering Details for Student %i", currentStudent + 1);
    printf("\n[?] Name   : ");
    scanf("%s", Students[currentStudent].name);
    printf("[?] Stream : ");
    scanf("%s", Students[currentStudent].stream);
    printf("[?] RollNo : ");
    scanf("%i", &Students[currentStudent].rollNo);
    printf("\n[i] Added Student %i Details", currentStudent + 1);
    currentStudent++;
}

// Function to load student data from a file
void LoadStudentData() {
    FILE* fileptr = fopen("Student.dat", "r");

    if (fileptr == NULL) {
        perror("Error opening the file");
        return;
    }

    while (fscanf(fileptr, "%d,%39[^,],%39[^,]\n", &Students[currentStudent].rollNo, Students[currentStudent].name, Students[currentStudent].stream) != EOF) {
        currentStudent++;
    }

    fclose(fileptr);
}

// Function to save student data to a file
void SaveStudentData() {
    FILE* fileptr = fopen("Student.dat", "a+");

    if (fileptr == NULL) {
        perror("Error opening the file");
        return;
    }

    printf("\n[i] Do you want to save the student records?\n");
    printf("[?] (y/n): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        for (int i = 0; i < currentStudent; i++) {
            fprintf(fileptr, "\n%d,%s,%s", Students[i].rollNo, Students[i].name, Students[i].stream);
            printf("\n[i] Saved Student %d", i + 1);
        }
        printf("\n[i] Data saved successfully.");
    } else {
        printf("\n[!] Data Discarded!");
    }
    fclose(fileptr);
}

int main() {
    printf("====== Student Record Management =====\n");

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Print Students\n");
        printf("4. Save Student Data\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AddStudent();
                break;
            case 2:
                SearchStudent();
                break;
            case 3:
                PrintStudents();
                break;
            case 4:
                SaveStudentData();
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\n[!] Invalid choice. Please select a valid option (1-5).\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
