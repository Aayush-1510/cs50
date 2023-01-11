#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long n=0;
    do
    {
        n = get_long("Credit Card Number: ");
    }while(n!=0);

    int r = 0, c = 0, sum = 0, multiplied_sum=0;
    long t = n;
    while(t != 0)
    {
        c++;
        r=t%10;
        if(c%2 != 0)
        {
            sum += r;
        }
        else
        {
            multiplied_sum += (r*2);
        }
        t /= 10;
    }
    int total_sum = sum + multiplied_sum;
    if( total_sum % 10 == 0 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}