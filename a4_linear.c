/*************************************/
    /* Name: Oomat Latipov */
    /* NetID: U13921223 */
    /* Program Description: This program */
    /* that reads a series of integer numbers */
    /* and saves them into an array. */
/*************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int n, searchNum, i;
    int *arr;
    char ch;


    while (1) {
        printf("Enter the number of input integers (0 to stop): ");

        // Checking if the user's input is valid
        if (scanf("%d", &n) != 1 || n < 0) {
            printf("Invalid number\n");
            // Clearing the input buffer
            while ((ch = getchar()) != '\n');
            continue;
        }

        if (n == 0) {
            break;
        }

        arr = (int*) malloc(n * sizeof(int));

        if (arr == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("Enter numbers: ");
        for (i = 0; i < n; i++) {
            scanf("%d", arr + i);
        }

        // Clear the input buffer to ignore extra input characters
        while (getchar() != '\n');

        printf("What is the search number? ");
        scanf("%d", &searchNum);

        int found = 0;
        for (i = 0; i < n; i++) {
            if (*(arr + i) == searchNum) {
                if (found == 0) {
                    printf("Found: %d is in position %d", searchNum, i);
                } else {
                    printf(", %d", i);
                }
                found = 1;
            }
        }

        if (found) {
            printf(" in the array.\n");
        } else {
            printf("Not found: %d is not in the array.\n", searchNum);
        }

        free(arr);
    }

    return 0;
}
