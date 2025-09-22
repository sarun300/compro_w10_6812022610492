#include <stdio.h>
#include <string.h>

typedef struct {
    float score;
} ReportCard;

int main() {
    int numStudents;
    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    ReportCard cards[numStudents]; // use VLA (variable-length array)
    float total = 0.0;
    int i;

    printf("Enter %d student scores (one per line):\n", numStudents);
    for (i = 0; i < numStudents; i++) {
        printf("Score %d: ", i + 1);
        scanf("%f", &cards[i].score);
        total += cards[i].score;
    }

    float average = total / numStudents;

    printf("\nNumber of students = %d\n", numStudents);
    printf("Average score = %.2f\n", average);

    return 0;
}
