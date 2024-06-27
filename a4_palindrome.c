/*************************************/
    /* Name: Oomat Latipov */
    /* NetID: U13921223 */
    /* Program Description: This program */
    /* that reads a user's input and */
    /* determines if the input is palindrome. */
/*************************************/
#include <stdio.h>

// Function to check if a character is a letter (uppercase or lowercase)
int isLetter(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to convert a character to lowercase
char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + ('a' - 'A');
    }
    return ch;
}

// Function to check if a string is a palindrome
int isPalindrome(char str[], int length) {
    int left = 0;
    int right = length - 1;

    while (left < right) {
        // Ignore non-alphabetical characters
        while (left < right && !isLetter(str[left])) {
            left++;
        }
        while (right > left && !isLetter(str[right])) {
            right--;
        }

        // Convert characters to lowercase for case-insensitive comparison
        if (toLower(str[left]) != toLower(str[right])) {
            return 0; // Not a palindrome
        }

        left++;
        right--;
    }

    return 1; // Palindrome
}

int main() {
    char message[101]; // Maximum message length + 1 for null terminator
    char choice;

    do {
        printf("Enter a message: ");
        fgets(message, sizeof(message), stdin);

        // Remove newline character if present
        int len = 0;
        while (message[len] != '\0') {
            if (message[len] == '\n') {
                message[len] = '\0';
                break;
            }
            len++;
        }

        // Check if the message is a palindrome
        if (isPalindrome(message, len)) {
            printf("Palindrome\n");
        } else {
            printf("Not a palindrome\n");
        }

        printf("Do you want to continue (N to stop)? ");
        scanf(" %c", &choice); // Notice the space before %c to consume whitespace

        // Clear input buffer
        while (getchar() != '\n');

    } while (choice != 'N' && choice != 'n');

    return 0;
}
