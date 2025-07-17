#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{

    char *word = (char *)malloc(100 * sizeof(char));
    int length;

    printf("\n-----------WELCOME TO THE PALINDROME CHECKER PROGRAM----------\n\n\n");
    printf("NOTE: You can input a word or a sentence but not number otherwise the conclusion will be made by filtering out the integers or symbols\n\n");

    printf("Enter the word or sentence that you want to check\n--> ");
    fgets(word, 100, stdin);

    word[strcspn(word, "\n")] = 0;
    length = strlen(word);

    char *cleaned = (char *)malloc((length + 1) * sizeof(char));
    int j = 0;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(word[i]))
        {
            cleaned[j++] = word[i];
        }
    }

    cleaned[j] = '\0';

    for (int i = 0; i < j; i++)
    {
        cleaned[i] = tolower(cleaned[i]);
    }

    char *rev = (char *)malloc((length + 1) * sizeof(char));

    for (int i = 0; i < j; i++)
    {
        rev[i] = cleaned[j - i - 1];
    }

    rev[j] = '\0';

    if (strcmp(cleaned, rev) == 0)
    {
        printf("PALINDROME!");
    }

    else
    {
        printf("NOT A PALINDROME");
    }

    free(word);
    free(cleaned);
    free(rev);
    return 0;
}
