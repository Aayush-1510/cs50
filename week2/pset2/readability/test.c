#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string text = get_string("TEXT: ");
    int i = get_int("i= :");
    char s = text[i];

    printf("%c\n",s);
}