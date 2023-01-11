#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(int argc, string argv[])
{
    string text = get_string("Text: ");
    //printf("%s\n",text);

    int c1 = count_letters(text);
    //printf("%i\n", c1);

    int c2 = count_words(text);
    //printf("%i\n", c2);

    int c3 = count_sentences(text);
    //printf("%i\n", c3);

    double index = 0, L = 0, S = 0;
    L = ((c1*1.0)/c2) * 100;
    //printf("%2f\n",L);

    S = ((c3*1.0)/c2) * 100;
    //printf("%2f\n",S);

    index = (0.0588 * L) - (0.296 * S) - 15.8;
    //printf("%f\n",index);

    int i= (int)round(index);
    if(i >= 16)
    {
        printf("Grade 16+\n");
    }
    else if(i < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n",i);
    }
}

//Function to count letters
int count_letters(string text)
{
    int c = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >='a' && text[i] <= 'z'))
        {
            //printf("%c\n",text[i]);
            c++;
        }
    }
    return c;
}

//Function to count words
int count_words(string text)
{
    int c = 0;
    for(int i = 0, n = strlen(text); i <= n; i++)
    {
        if(text[i] == 32 || text[i] == '\0')
        {
            //printf("%c\n",text[i]);
            c++;
        }
    }
    return c;
}

//Function to count sentences
int count_sentences(string text)
{
    int c = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            //printf("%c\n",text[i]);
            c++;
        }
    }
    return c;
}