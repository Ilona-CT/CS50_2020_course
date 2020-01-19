#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);

int main(void)
{
    //getting height from 
    int n = get_positive_int("Height: ");
    // making a pyramid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            //reverse pyramid right alined
            if (j < n - i - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
    
}

// positive integer between 1 and 8 inclusive where we return integer but take in string from user
int get_positive_int(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (1 > n || 8 < n);
    return n;
}
