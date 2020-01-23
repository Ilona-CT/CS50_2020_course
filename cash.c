#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // get float input from user
    float change;
    do
    {
       change = get_float("Change owed: ");
    }
    while (change < 0.00);
    // round up to hundreds in one transaction
    int n = round(change * 100);
    
    // determining integers required
    int quarter, dime, nickel, penny, greedy;
    
    // cashier
    quarter = n / 25;
    dime = (n % 25) / 10;
    nickel = ((n % 25) % 10) / 5;
    penny = ((n % 25) % 10) % 5;
    greedy = quarter + dime + nickel + penny;
    printf("%i\n", greedy);
}
