#include <stdio.h>
#include <cs50.h>
#include <math.h>

int luhns(long l);

int main(void)
{
    //getting long which length's is 13, 15 or 16
    int a, b, c, d, k, sumb = 0, sumd = 0;
    long l;
    do
    {
        l = get_long("Number: ");
    }
    while (l < 0);
    
    if (((int)luhns % 2) != 0)
    {
        printf("INVALID\n");
    }
    else if (l < 999999999999 || ((9999999999999 < l) && (l < 100000000000000)) || l > 9999999999999999)
    {
        printf("INVALID\n");
    }
    else
    {
        //diminish number by 10 until it is 2 digits long
        k = l;
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
}
//calculating luhns number
int luhns(long l)
{    
    long i;
    int a, b, c, d, sumb = 0, sumd = 0, luhns = 0;
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
    return luhns;
}
