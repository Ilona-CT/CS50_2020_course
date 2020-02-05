#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char substitute(char a[], char b[]);

int main(int argc, string argv[])
{
    // check if there are more than 2 arguments, if not - exit the program
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // check the length of second argument = our desired one
    int n = strlen(argv[1]);
    // check if length is different than 26, if not - exit the program
    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // if length is 26 then verify input validity, if not - exit the program
    else
    {
        // go with lop through each character of argv[1]
        for (int i = 0; i < n; i++)
        {
            // check if all characters are letters, if not - exit the program
            if (isalpha(argv[1][i]) == false)
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
            // if all characters are alpha then check with double loop if any of them is not repeated
            else
            {
                // if all are alpha then check if there are no repeated characters
                if (i == n - 1)
                {
                    for (i = 0; i < n - 1; i++)
                    {
                        for (int j = i + 1; j < n; j++)
                        {
                            if (toupper(argv[1][i]) == toupper(argv[1][j]))
                            {
                                printf("Key must not contain repeated characters.\n");
                                return 1;
                            }
                            else
                            {
                                if (i == n - 2)
                                {
                                    string p = get_string("plaintext: ");
                                    printf("ciphertext: ");
                                    return substitute(argv[1], p);
                                }
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
}

char substitute(char a[], char b[])
{
    int m = strlen(a);
    int n = strlen(b);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(b[i]))
        {
            if (islower(b[i]))
            {
                for (char j = 'a'; j <= 'z'; j++)
                {
                    if (b[i] == j)
                    {
                        printf("%c", tolower(a[j - 97]));
                    }

                }
            }
            else
            {
                for (char j = 'A'; j <= 'Z'; j++)
                {
                    if (b[i] == j)
                    {
                        printf("%c", toupper(a[j - 65]));
                    }

                }
            }
        }
        else
        {
            printf("%c", b[i]);
        }
    }
    printf("\n");
    return 0;
}