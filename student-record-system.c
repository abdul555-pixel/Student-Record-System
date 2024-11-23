#include <stdio.h>
#include <string.h>

// Define the Student structure
struct Student {
    char name[50];  // Ensure 'name' is modifiable
    int age;
    float grade;
};

void addStudent(struct Student students[], int *count) {
    printf("Enter student's name: ");
    fgets(students[*count].name, sizeof(students[*count].name), stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0'; // Remove newline

    printf("Enter student's age: ");
    scanf("%d", &students[*count].age);

    printf("Enter student's grade: ");
    scanf("%f", &students[*count].grade);
    getchar(); // Consume leftover newline character

    (*count)++;
}

void displayStudents(struct Student students[], int count) {
    printf("Student Records:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d, Grade: %.2f\n",
               students[i].name, students[i].age, students[i].grade);
    }
}

int main() {
    struct Student students[100];
    int count = 0;

    // Example: Add and display students
    addStudent(students, &count);
    displayStudents(students, count);

    return 0;
}
