#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    long n = get_long("Credit Card Number: ");
        //printf("%li",n);
    long t2 = n;
    for(int r = 0 ; t2 != 0 ; t2 /= 10)
    {
        if(t2<10)
        {
            break;
        }
        else
        {
            r = t2 % 100;
            printf("%i\n",r);
        }
    }
}