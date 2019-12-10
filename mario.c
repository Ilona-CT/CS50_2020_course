#include <cs50.h>
#include <stdio.h>

void pyramid(int n);
// i - line, j - column,
int i, j;

int main(void)
{
    // getting height
    int n = get_int("Type positive integer between 1 and 8: ");

    if (0 < n && n < 9)
    {
        pyramid(n);
    }
    else
    {
        do
        {
            n = get_int("That is not a positive integer between 1 and 8. Try again: ");
        }
        while (1 > n || n > 8);
        pyramid(n);
    } 
}


//loop pyramid, i - line, j - column
void pyramid(int n)
{
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i < n - j - 1)
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
