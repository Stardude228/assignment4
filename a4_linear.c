/*************************************/
    /* Name: Oomat Latipov */
    /* NetID: U13921223 */
    /* Program Description: This program */
    /* that reads a series of integer numbers */
    /* and saves them into an array. */
/*************************************/
#include <stdio.h>

int main() {

    // Declaring variables for future use
    int n, searchNum, i;
    char ch;


    while (1) {
    
        // User prompt
        printf("Enter the number of input integers (0 to stop): ");

        // Checking if the user's input is valid
        if (scanf("%d", &n) != 1 || n < 0) {
            printf("Invalid number \n \n");
            // Clearing the input buffer
            while ((ch = getchar()) != '\n');
            continue;
        }

        // Checking if the user wants to end the program
        if (n == 0) {
            break;
        }

        // Variable Length Array for dynamic allocation
        int arr[n];

        // Prompt for user to enter numbers
        printf("Enter numbers: ");
        for (i = 0; i < n; i++) {
            if (scanf("%d", arr + i) != 1) {
                printf("Invalid input. Please enter integers only.\n");
                // Clear the input buffer
                while (getchar() != '\n');
                i--;  // Decrement i to retry the current index
            }
        }

        // Clear the input buffer to ignore extra input characters
        while (getchar() != '\n');

        // Prompt for user to enter the search number
        printf("What is the search number? ");
        if (scanf("%d", &searchNum) != 1) {
            printf("Invalid number\n \n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        // Variable for the case if the number is found
        int found = 0;

        // A loop for number searching
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

        // Printing the right numbers
        if (!found) {
            printf("Not found: %d is not in the array.\n \n", searchNum);
        } else {
            printf(" in the array.\n \n");
        }
    }

    return 0;
}
