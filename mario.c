#include <cs50.h>
#include <stdio.h>

int i, j, n, k;

int main(void)
{
    // getting height
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    
    //pyramid
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2 * n + 2; j++)
        {   
            if (i < n - j - 1)
            {
                printf(" ");
            }   
            else if (j == n || j == n + 1)
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


