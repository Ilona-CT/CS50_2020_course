#include <stdio.h>
#include <cs50.h>
#include <math.h>

void cashier (float f);

int n;
int quarter;
int dime;
int nickle;
int penny;
int change;

int main(void)
{
   float f;
   do
   {
       f = get_float("Change owed:");
   }
   while (f<=0);
   cashier (f);
}


void cashier (float f)
{
    n = round(f*100);
    if (n >= 0.25)
      {
          quarter = n/25;
          dime = (n%25)/10;
          nickle = ((n%25)%10)/5;
          penny = ((n%25)%10)%5;
          change = quarter + dime + nickle + penny;
          printf("%i\n", change);
       }
     else if (n>=0.10 && n<0.25)
       {
          dime = n/10;
          nickle = (n%10)/5;
          penny = (n%10)%5;
          change = dime + nickle + penny;
          printf("%i\n", change);
       }
    else if (n>=0.05 && n<0.10)
       {
          nickle = n/5;
          penny = n%5;
          change = nickle + penny;
          printf("%i\n", change);
       }
    else
       {
          penny = n%5;
          printf("%i\n", penny);
       }
}
