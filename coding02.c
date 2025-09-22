#include <stdio.h>

#define NUM_STUDENTS 3
#define NUM_SUBJECTS 3

// Subject index
enum { MATH, PHYSICS, CHEMISTRY };

// Function to print header
void printScoreTableHeader() {
    printf("\nScore Table:\n");
    printf("%-10s %-10s %-10s %-10s\n", "Student", "Math", "Physics", "Chemistry");
}

// Function to print student scores
void printStudentScores(float scores[NUM_STUDENTS][NUM_SUBJECTS]) {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%-10d %-10.2f %-10.2f %-10.2f\n",
               i + 1,
               scores[i][MATH],
               scores[i][PHYSICS],
               scores[i][CHEMISTRY]);
    }
}

// Function to calculate and print average per subject
void printSubjectAverages(float scores[NUM_STUDENTS][NUM_SUBJECTS]) {
    float subjectTotals[NUM_SUBJECTS] = {0};

    // Sum scores for each subject
    for (int i = 0; i < NUM_STUDENTS; i++) {
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            subjectTotals[j] += scores[i][j];
        }
    }

    printf("\nAverage per subject:\n");
    printf("Math: %.2f\n", subjectTotals[MATH] / NUM_STUDENTS);
    printf("Physics: %.2f\n", subjectTotals[PHYSICS] / NUM_STUDENTS);
    printf("Chemistry: %.2f\n", subjectTotals[CHEMISTRY] / NUM_STUDENTS);
}

int main() {
    float scores[NUM_STUDENTS][NUM_SUBJECTS];

    // Input scores
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter scores for Student %d:\n", i + 1);

        printf("Math: ");
        scanf("%f", &scores[i][MATH]);

        printf("Physics: ");
        scanf("%f", &scores[i][PHYSICS]);

        printf("Chemistry: ");
        scanf("%f", &scores[i][CHEMISTRY]);
    }

    // Output
    printScoreTableHeader();
    printStudentScores(scores);
    printSubjectAverages(scores);

    return 0;
}
