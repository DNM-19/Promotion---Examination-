#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure to store student information
struct Student {
    int id;
    char name[50];
    int age;
    char grade[5];
};

struct Student students[MAX];
int count = 0;

// Function declarations
void addStudent();
void viewStudents();
void updateStudent();
void deleteStudent();
void searchStudent();

int main() {
    int choice;

    while (1) {
        printf("\n=== Student Management System ===\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Search Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: searchStudent(); break;
            case 6: printf("Exiting program. Goodbye!\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a new student
void addStudent() {
    if (count >= MAX) {
        printf("Student list is full!\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &students[count].id);
    printf("Enter Name: ");
    scanf(" %[^\n]%*c", students[count].name); // Read string with spaces
    printf("Enter Age: ");
    scanf("%d", &students[count].age);
    printf("Enter Grade: ");
    scanf("%s", students[count].grade);

    count++;
    printf("Student added successfully!\n");
}

// Function to view all students
void viewStudents() {
    if (count == 0) {
        printf("No students to display!\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Age: %d | Grade: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].grade);
    }
}

// Function to update student information
void updateStudent() {
    int id, found = 0;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter new Name: ");
            scanf(" %[^\n]%*c", students[i].name);
            printf("Enter new Age: ");
            scanf("%d", &students[i].age);
            printf("Enter new Grade: ");
            scanf("%s", students[i].grade);
            printf("Student updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found!\n", id);
    }
}

// Function to delete a student
void deleteStudent() {
    int id, found = 0;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1]; // Shift students
            }
            count--;
            printf("Student deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found!\n", id);
    }
}

// Function to search for a student
void searchStudent() {
    int id, found = 0;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Student Found: ID: %d | Name: %s | Age: %d | Grade: %s\n",
                   students[i].id, students[i].name, students[i].age, students[i].grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found!\n", id);
    }
}
