#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

double calculateAverage(int grades[], int n);
int findHighest(int grades[], int n);
int findLowest(int grades[], int n);
void printPassed(char names[][NAME_LEN], int grades[], int n);

int main() {
    int n;
    char names[MAX_STUDENTS][NAME_LEN];
    int grades[MAX_STUDENTS];

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", names[i]);
        printf("Enter grade of %s: ", names[i]);
        scanf("%d", &grades[i]);
    }

    printf("--- Results ---\n");
    printf("Average grade: %.2f\n", calculateAverage(grades, n));
    printf("Highest grade: %d\n", findHighest(grades, n));
    printf("Lowest grade: %d\n", findLowest(grades, n));

    printf("\nStudents who passed:\n");
    printPassed(names, grades, n);

    return 0;
}

double calculateAverage(int grades[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += grades[i];
    return (double)sum / n;
}

int findHighest(int grades[], int n) {
    int max = grades[0];
    for (int i = 1; i < n; i++) if (grades[i] > max) max = grades[i];
    return max;
}

int findLowest(int grades[], int n) {
    int min = grades[0];
    for (int i = 1; i < n; i++) if (grades[i] < min) min = grades[i];
    return min;
}

void printPassed(char names[][NAME_LEN], int grades[], int n) {
    for (int i = 0; i < n; i++) if (grades[i] >= 60) printf("%s\n", names[i]);
}
