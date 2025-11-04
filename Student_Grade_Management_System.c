//Student Grade Management System (C Program) 
#include <stdio.h> 
#include <string.h> 
 
#define MAX 100 // Maximum number of students 
#define SUB 3   // Number of subjects per student 
 
// Arrays to store student data 
int roll[MAX]; 
char name[MAX][50]; 
int marks[MAX][SUB]; 
float total[MAX], percent[MAX]; 
char grade[MAX]; 
int count = 0; // Number of students 
 
// Function declarations 
void addStudent(); 
void displayAll(); 
void searchStudent(); 
void calculateGrades(); 
void sortStudents(); 
void deleteStudent(); 
void updateStudent(); 
 
int main() 
{ 
    int choice; 
 
    while (1) 
    { 
        printf("\n===== STUDENT GRADE MANAGEMENT SYSTEM =====\n"); 
        printf("1. Add Student Record\n"); 
        printf("2. Display All Students\n"); 
        printf("3. Search Student by Roll Number\n"); 
        printf("4. Calculate Grades\n"); 
        printf("5. Sort Students by Total Marks\n"); 
        printf("6. Delete a Student Record\n"); 
        printf("7. Update a Student Record\n"); 
        printf("8. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) 
        { 
        case 1: 
            addStudent(); 
            break; 
        case 2: 
            displayAll(); 
            break; 
        case 3: 
            searchStudent(); 
            break; 
        case 4: 
            calculateGrades(); 
            break; 
        case 5: 
            sortStudents(); 
            break; 
        case 6: 
            deleteStudent(); 
            break; 
        case 7: 
            updateStudent(); 
            break; 
        case 8: 
            printf("Exiting program...\n"); 
            return 0; 
        default: 
            printf("Invalid choice! Try again.\n"); 
        } 
    } 
} 
 
// 1. Add student record 
void addStudent() 
{ 
    if (count >= MAX) 
    { 
        printf("Can't add more students!\n"); 
        return; 
    } 
 
    printf("Enter name: "); 
    scanf(" %[^\n]", name[count]); 
    printf("Enter roll number: "); 
    scanf("%d", &roll[count]); 
 
    total[count] = 0; 
    for (int i = 0; i < SUB; i++) 
    { 
        printf("Enter marks in subject %d: ", i + 1); 
        scanf("%d", &marks[count][i]); 
        total[count] += marks[count][i]; 
    } 
 
    percent[count] = total[count] / SUB; 
    grade[count] = ' '; // Will be calculated later 
    count++; 
 
    printf("Student added successfully!\n"); 
} 
 
// 2. Display all students 
void displayAll() 
{ 
    if (count == 0) 
    { 
        printf("No records found!\n"); 
        return; 
    } 
 
    printf("\n%-10s %-15s %-10s %-10s %-10s\n", "Roll No", "Name", "Total", "Percent", "Grade"); 
    printf("------------------------------------------------------------\n"); 
 
    for (int i = 0; i < count; i++) 
    { 
        printf("%-10d %-15s %-10.2f %-10.2f %-10c\n", 
               roll[i], name[i], total[i], percent[i], grade[i]); 
    } 
} 
 
// 3. Search student by roll number 
void searchStudent() 
{ 
    int r, found = 0; 
    printf("Enter roll number to search: "); 
    scanf("%d", &r); 
 
    for (int i = 0; i < count; i++) 
    { 
        if (roll[i] == r) 
        { 
            printf("\nStudent Found:\n"); 
            printf("Name: %s\nRoll: %d\nTotal: %.2f\nPercent: %.2f\nGrade: %c\n", 
                   name[i], roll[i], total[i], percent[i], grade[i]); 
            found = 1; 
            break; 
        } 
    } 
 
    if (!found) 
        printf("Student not found!\n"); 
} 
 
// 4. Calculate grades 
void calculateGrades() 
{ 
    for (int i = 0; i < count; i++) 
    { 
        if (percent[i] >= 90) 
            grade[i] = 'A'; 
        else if (percent[i] >= 75) 
            grade[i] = 'B'; 
        else if (percent[i] >= 60) 
            grade[i] = 'C'; 
        else if (percent[i] >= 45) 
            grade[i] = 'D'; 
        else 
            grade[i] = 'F'; 
    } 
    printf("Grades calculated successfully!\n"); 
} 
 
// 5. Sort students by total marks (descending) 
void sortStudents() 
{ 
    for (int i = 0; i < count - 1; i++) 
    { 
        for (int j = 0; j < count - i - 1; j++) 
        { 
            if (total[j] < total[j + 1]) 
            { 
                // Swap everything 
                float temp = total[j]; 
                total[j] = total[j + 1]; 
                total[j + 1] = temp; 
                float p = percent[j]; 
                percent[j] = percent[j + 1]; 
                percent[j + 1] = p; 
                char g = grade[j]; 
                grade[j] = grade[j + 1]; 
                grade[j + 1] = g; 
                int r = roll[j]; 
                roll[j] = roll[j + 1]; 
                roll[j + 1] = r; 
 
                char n[50]; 
                strcpy(n, name[j]); 
                strcpy(name[j], name[j + 1]); 
                strcpy(name[j + 1], n); 
 
                for (int k = 0; k < SUB; k++) 
                { 
                    int m = marks[j][k]; 
                    marks[j][k] = marks[j + 1][k]; 
                    marks[j + 1][k] = m; 
                } 
            } 
        } 
    } 
    printf("Students sorted by total marks (highest to lowest).\n"); 
} 
 
// 6. Delete student record 
void deleteStudent() 
{ 
    int r, pos = -1; 
    printf("Enter roll number to delete: "); 
    scanf("%d", &r); 
 
    for (int i = 0; i < count; i++) 
    { 
        if (roll[i] == r) 
        { 
            pos = i; 
            break; 
        } 
    } 
 
    if (pos == -1) 
    { 
        printf("Student not found!\n"); 
        return; 
    } 
 
    for (int i = pos; i < count - 1; i++) 
    { 
        roll[i] = roll[i + 1]; 
        strcpy(name[i], name[i + 1]); 
        total[i] = total[i + 1]; 
        percent[i] = percent[i + 1]; 
        grade[i] = grade[i + 1]; 
        for (int j = 0; j < SUB; j++) 
            marks[i][j] = marks[i + 1][j]; 
    } 
 
    count--; 
    printf("Student record deleted successfully!\n"); 
} 
 
// 7. Update student record 
void updateStudent() 
{ 
    int r, found = 0; 
    printf("Enter roll number to update: "); 
    scanf("%d", &r); 
 
    for (int i = 0; i < count; i++) 
    { 
        if (roll[i] == r) 
        { 
            found = 1; 
            printf("Enter new marks for %d subjects:\n", SUB); 
            total[i] = 0; 
            for (int j = 0; j < SUB; j++) 
            { 
                printf("Subject %d: ", j + 1); 
                scanf("%d", &marks[i][j]); 
                total[i] += marks[i][j]; 
            } 
            percent[i] = total[i] / SUB; 
            printf("Record updated successfully!\n"); 
            break; 
        } 
    } 
 
    if (!found) 
        printf("Student not found!\n"); 
} 