#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);

    // Remove newline if present
    if (str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
        len--;
    }

    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            for (int j = i + 1; j < len && str[j] != ' '; j++)
            {
                printf("%c", str[j]);
            }
            printf(" ");
        }
    }

    // Print first word
    for (int i = 0; str[i] != ' ' && str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
    }

    return 0;


/*
                char str[100];
                char *words[50];
                int count = 0;

                printf("Enter a string: ");
                fgets(str, sizeof(str), stdin);

                // Remove newline character
                str[strcspn(str, "\n")] = '\0';

                // Split string into words
                char *token = strtok(str, " ");

                while (token != NULL)
                {
                    words[count++] = token;
                    token = strtok(NULL, " ");
                }

                // Print words in reverse order
                printf("Reversed sentence: ");

                for (int i = count - 1; i >= 0; i--)
                {
                    printf("%s ", words[i]);
                }

                printf("\n");

                return 0;
*/




}