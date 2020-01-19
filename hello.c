#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //ask for name
    string name = get_string("What is your name?\n");
    //print out hello + string name input collected line before
    printf("hello, %s\n", name);
}
