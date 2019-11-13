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
        return 1;
    }
    // if less or more than 2 arguments - print error message
    else
    {
        printf("Usage: ./caesar key\n");
    }
}
// cipher
char cipher(int k)
{
    string s = get_string("plaintext: ");
    printf("ciphertext: ");
    // repeat until string has ended
    for (int i = 0, m = strlen(s); i < m; i++)
    {
        // k is a number provided by user in main function
        char x = s[i] + k;
        // modulus of division if value greater than 'z' or 'Z'
        char y = x % s[i];
        // as long as we are betwen 'A' and 'Z'
        if (s[i] > 'A' - 1 && s[i] < 'Z' + 1)
        {
            // if after increasing letter by number provided by user we are over 'Z' - use modulus
            if (x > 'Z')
            {
                printf("%c", 'A' - 1 + y);
            }
            else
            {
                printf("%c", x);
            }
        }
        else if (s[i] > 'a' - 1 && s[i] < 'z' + 1)
        {
            // if after increasing letter by number provided by user we are over 'z' - use modulus
            if (x > 'z')
            {
                printf("%c", 'a' - 1 + y);
            }
            else
            {
                printf("%c", x);
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
