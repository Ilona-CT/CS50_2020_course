#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char cipher(int k);

int main(int argc, string argv[])
{
    // naming strings, p - plaintext, c - ciphertext
    string p, c = 0;
    int k;

    // when user puts less or more than 2 arguments error message will occur
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // going through each character of argv[1] one by one checking if it is digit
    else
    {
        for (int i = 0, n = strlen(argv[1]); isdigit(argv[1][i]) && i < n; i++)
        {
            // when we reach last character and it is digit change argv[1] to digit
            if (i == n - 1)
            {
                k = atoi(argv[1]);
                // getting plaintext from user
                return cipher(k);
            }
        }
        printf("Usage: ./caesar key\n");
        return 1;
    }
}


char cipher(int k)
{
    // plaintext
    string p = get_string("plaintext: ");
    int n = strlen(p);
    // ciphertext
    printf("ciphertext: ");
    for(int i = 0; i < n; i++)
    {
        if(isalpha(p[i]))
        {
            printf("%c", p[i] + k % 26);
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
    return 0;
}