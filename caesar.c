#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char cipher(int k);

int main(int argc, string argv[])
{
    // check if user put 2 arguments in
    if (argc == 2)
    {    
        int j, n, k;
        // check if argument put in is all numbers
        for (j = 0, n = strlen(argv[1]); j < n && isdigit(argv[1][j]); j++)
        {
            if (j == n - 1)
            {
                // if 1 arg and all digits - print success and arg no 1
                k = atoi(argv[1]);
                cipher(k);
                return 0;
            }
        }
        printf("Usage: ./caesar key\n");
    }
    // if less or more than 2 arguments - print error message
    else
    {
        printf("Usage: ./caesar key\n");
    }
    return 1;
}
// cipher
char cipher(int k)
{
    // defining l when k > 25 and int o not to repeat ourselves
    int l = k % 25, o;
    
    string s = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // when char provided is between a or z        
        if (s[i] > 'a' - 1 && s[i] < 'z' + 1)
        {
            if (k > 49)
            {
                o = s[i] + l - (k/25);
                if (o > 'z')
                {
                    char x = ('a' - 1) + (o - 'z');
                    printf("%c", x);
                }
                else
                {
                    char y = o;
                    printf("%c", y);
                }
            }
            if (k > 25 && k < 50)
            {
                o = s[i] + l;
                if (o > 'z')
                {
                    char x = ('a' - 1) + (o - 'z');
                    printf("%c", x);
                }
                else
                {
                    char y = o;
                    printf("%c", y);
                }
            }
            else
            {
                o = s[i] + k;
                if (o > 'z')
                {
                    char x = 'a' - 1 + (o - 'z');
                    printf("%c", x);
                }
                else
                {
                    char y = o;
                    printf("%c", y);
                }
            }  
        }
        // when char provided is between A and Z
        else if (s[i] > 'A' - 1 && s[i] < 'Z' + 1)
        {
            if (k > 49)
            {
                o = s[i] + l - (k/25);
                if (o > 'Z')
                {
                    char x = ('A' - 1) + (o - 'Z');
                    printf("%c", x);
                }
                else
                {
                    char y = o;
                    printf("%c", y);
                }
            }
            if (k > 25 && k < 50)
            {
                o = s[i] + l;
                if (o > 'Z')
                {
                    char x = ('A' - 1) + (o - 'Z');
                    printf("%c", x);
                }
                else
                {
                    char y = o;
                    printf("%c", y);
                }
            }
            else
            {
                o = s[i] + k;
                if (o > 'Z')
                {
                    char x = 'A' - 1 + (o - 'Z');
                    printf("%c", x);
                }
                else
                {
                    char y = o;
                    printf("%c", y);
                }
            }
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
}
