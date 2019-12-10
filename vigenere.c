#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);
char cipher(int k);
string ciphertext(string s);
int o, i, l, m;

int main(int argc, string argv[])
{
    // check if we have 1 argument
    if (argc == 2)
    {   
        // check if argument put in is all letters
        for (int j = 0, n = strlen(argv[1]); j < n && isalpha(argv[1][j]); j++)
        {
            if (j == n - 1)
            {
                string s = get_string("plaintext: ");
                m = strlen(s);
                printf("ciphertext: ");
                int key;
                j = 0;
                for (i = 0; i < m; i++, j++)
                {  
                    if (j == n)
                    {
                        j = 0;
                    }
                    key = shift(argv[1][j]);
                    o = s[i] + key;
                    // when char provided is between a or z        
                    if (s[i] > 'a' - 1 && s[i] < 'z' + 1)
                    {
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
                    else if (s[i] > 'A' - 1 && s[i] < 'Z' + 1)
                    {
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
                    else
                    {
                        j = j - 1;
                        printf("%c", s[i]);
                    }
                }
                printf("\n");
                return 0;
            }
        }
    }
    // if less or more than 2 arguments - print error message
    else
    {
        printf("Usage: ./caesar key\n");
    }
    // exit if none of arguments fulfilled
    return 1;
}


// shifting alphabet to numbers
int shift(char c)
{
    int shift;
    if (c >= 'a' && c <= 'z')
    {
        return shift = c - 97;
    }
    else 
    {
        return shift = c - 65;
    }
}

