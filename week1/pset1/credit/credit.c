#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

long checksum(long n);

int main(void)
{
    int r;
    while(true)
    {
        long n = get_long("Credit Card Number: ");
        //printf("%li",n);
        long c=0;
        long t=n;
        while(t!=0)
        {
            c++;
            t/=10;
        }
        printf("%li\n", c);
        if(c==10)
        {
            printf("INVALID\n");
            break ;
        }
        else if(c==15)
        {
            //maybe amex
            long t2 = n;
            for(r = 0 ; t2 != 0 ; t2 /= 10)
            {
                if(t2<10)
                {
                    break;
                }
                else
                {
                    r = t2 % 100;
                    //printf("%i\n",r);
                }
            }
            if(r == 34 || r == 37)
            {
                long b1=checksum(n);
                if(b1==1)
                {
                    printf("AMEX\n");
                    break;
                }
            }
            else
            {
                printf("INVALID\n");
                break;
            }
        }
        else if(c==13)
        {
            //maybe visa
            long t2 = n;
            for(r = 0 ; t2 != 0 ; t2 /= 10)
            {
                r = t2 % 10;
                //printf("%i\n",r);
            }
            if(r == 4)
            {
                long b2=checksum(n);
                if (b2==1)
                {
                    printf("VISA\n");
                    break;
                }
                else
                {
                    printf("INVALID\n");
                    break;
                }
            }
            else
            {
                printf("INVALID\n");
                break;
            }
        }
        else if(c==16)
        {
            //maybe mastercard or visa
            long t2 = n;
            for(r = 0 ; t2 != 0 ; t2 /= 10)
            {
                if(t2<10)
                {
                    break;
                }
                else
                {
                    r = t2 % 100;
                    //printf("%i\n",r);
                }
            }
            if((r/10) == 4)
            {
                //maybe visa
                //printf("MAybe visa condition sucessfull:)\n");
                long b3=checksum(n);
                if (b3==1)
                {
                    printf("VISA\n");
                    break;
                }
                else
                {
                    printf("INVALID\n");
                    break;
                }
            }
            else if(r > 50 && r < 56)
            {
                //maybe mastercard
                    long b4=checksum(n);
                    if (b4==1)
                    {
                        printf("MASTERCARD\n");
                        break;
                    }
                    else
                    {
                        printf("INVALID\n");
                        break;
                    }
            }
            else
            {
                printf("INVALID\n");
                break;
            }
        }
        if(n==0)
        break;
    }
}

long checksum(long n)
{
    //return 1;
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
            int t1=r*2;
            for(int j=0 ; t1 != 0 ; t1 /= 10)
            {
                j = t1 % 10;
                multiplied_sum += j;
            }
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