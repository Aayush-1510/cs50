#include <cs50.h>
#include <stdio.h>

int main(void)
{//start of main()
    int h=0;
    //loop for taking input from user
    while(true)
    {
        h = get_int("Height: ");
        if(h > 0 && h < 9)
        {
            //printf("Height entered: %i " ,h);
            printf("\n");
            break;
        }
        else
        {
            printf("<ERROR>\n<Please renter>\n");
        }
    }

    for( int i=1;i<=h;i++)
    {//Start of outer loop

        for(int a=i;a<h;a++)
        {
            printf(" ");
        }
        for( int j=1;j<=i;j++)
        {//Start of reversed triangle loop
            printf("#");
        }//End of reversed triangle loop

        printf("  ");// to print the two white spaces between the triangles

        for( int b=1;b<=i;b++)
        {
            printf("#");
        }
        printf("\n");
    }//End of outer loop
}//End of main()