#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{

    char *word = (char *)malloc(250 * sizeof(char));
    int length;

    // Displaying Welcome messsage and input rules...
    printf("\n-----------WELCOME TO THE PALINDROME CHECKER PROGRAM----------\n\n\n");
    printf("NOTE: You can input a word or a sentence but not number otherwise the conclusion will be made by filtering out the integers or symbols\n\n");

    printf("Enter the word or sentence that you want to check\n--> ");
    fgets(word, 250, stdin); // taking input from the user

    word[strcspn(word, "\n")] = 0; // removing the newline character left by fgets
    length = strlen(word);

    char *cleaned = (char *)malloc((length + 1) * sizeof(char)); // to store only alphabets from the input
    int j = 0;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(word[i])) // Filtering out digits, spaces or special characters
        {
            cleaned[j++] = word[i];
        }
    }

    cleaned[j] = '\0'; // null terminating the cleaned string

    for (int i = 0; i < j; i++)
    {
        cleaned[i] = tolower(cleaned[i]); // converting all lettes to lower case
    }

    char *rev = (char *)malloc((length + 1) * sizeof(char)); // to hold reversed form of the cleaned string

    for (int i = 0; i < j; i++)
    {
        rev[i] = cleaned[j - i - 1]; // reversing the cleaned string
    }

    rev[j] = '\0';

    if (strcmp(cleaned, rev) == 0) // result
    {
        printf("PALINDROME!\n");
    }

    else
    {
        printf("NOT A PALINDROME!\n");
    }

    free(word); // freeing the dynamically allocated memory
    free(cleaned);
    free(rev);
    return 0;
}
