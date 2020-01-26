#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //getting long greater than 0
    int k, a, b, c, d, sumb = 0, sumd = 0, luhns;
    long l, i;
    do
    {
        l = get_long("Number: ");
    }
    while (l < 0);
    
    // calculating luhns number
    for (i = 10; i < l; i *= 100)
    {
        a = (((l % (i * 10)) - (l % i)) / i) * 2;
        if (a < 10)
        {
            b = a;
        }
        else
        {
            b = (a - 10) + 1;
        }
        sumb += b;
    }
    for (i = 1; i < l; i *= 100)
    {
        c = (((l % (i * 10)) - (l % i)) / i);
        if (c < 10)
        {
            d = c;
        }
        else
        {
            d = (c - 10) + 1;
        }
        sumd += d;
    }
    luhns = sumb + sumd;
    printf("%i\n", luhns);
    
    // if the number is not 13 or 15 or 16 digits long print invalid
    if (l < 999999999999 || ((9999999999999 < l) && (l < 100000000000000)) || l > 9999999999999999)
    {
        printf("INVALID\n");
    }
    // if modulo of luhns number is 0 then verify 1-2 first digits and CC length
    else if (luhns % 10 == 0)
    {
        //diminish number by 10 until it is 2 digits long
        k = l / 1000000000000;
        do
        {
            k /= 10;
        }
        while (k > 99);

        // if first to numbers are 34 or 37 it is AMEX
        if ((k == 34 || k == 37) && (99999999999999 < l && l < 1000000000000000))
        {
            printf("AMEX\n");
        }
        // if first to numbers are either of: 51, 52, 53, 54, 55, 55 it is MasterCard
        else if ((k > 50 && k < 56) && (999999999999999 < l && l < 10000000000000000))
        {
            printf("MASTERCARD\n");
        }
        // if first number starts with digit 4 it is Visa
        else if ((k > 39 && k < 50) && ((999999999999999 < l && l < 10000000000000000) || (999999999999 < l && l < 10000000000000)))
        {
            printf("VISA\n");
        }
        // otherwise CC is invalid
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

