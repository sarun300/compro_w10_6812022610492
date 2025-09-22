#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100

// Function to remove trailing newline from fgets()
void removeNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Function to compare strings case-insensitively (for robustness)
int stringsEqualIgnoreCase(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (tolower((unsigned char)*str1) != tolower((unsigned char)*str2)) {
            return 0;
        }
        str1++;
        str2++;
    }
    return *str1 == *str2;
}

int main() {
    char customer1[MAX_NAME_LEN];
    char customer2[MAX_NAME_LEN];

    // Input for customer 1
    printf("Enter name of customer 1: ");
    if (fgets(customer1, sizeof(customer1), stdin) == NULL) {
        printf("Input error for customer 1.\n");
        return 1;
    }
    removeNewline(customer1);

    // Input for customer 2
    printf("Enter name of customer 2: ");
    if (fgets(customer2, sizeof(customer2), stdin) == NULL) {
        printf("Input error for customer 2.\n");
        return 1;
    }
    removeNewline(customer2);

    size_t len1 = strlen(customer1);
    size_t len2 = strlen(customer2);

    // Check if names are the same
    if (strcmp(customer1, customer2) == 0) {
        printf("Both of your names are the same, which is %s.\n", customer1);
        printf("The length of the name is %zu characters.\n", len1);
    } else {
        printf("Customer 1: %s (%zu characters)\n", customer1, len1);
        printf("Customer 2: %s (%zu characters)\n", customer2, len2);
    }

    return 0;
}
