#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key = argv[1];
    //if user did not enter anything at the CLI
    if(argv[1] == (void *)0)
    {
        printf("Usage: ./substitution <KEY>\n");
        return 1;
    }
    //key less than 26characters
    if(strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //to check if all 26 char is all aplha
    for(int i = 0, n = strlen(key); i < n; i++)
    {
        char c = key[i];
        if(isalpha(c) == 0)
        {
            printf("Key must only contain alphabetical characters\n");
            return 1;
        }
    }
    //to check for repeated aplha

    int count = 0;
    for(int i = 0; i < strlen(key); i++)
    {
        count = 1;
        for(int j = i+1; j < strlen(key); j++)
        {
            if(toupper(key[i]) == toupper(key[j]))
            {
                count++;
                key[j] = '0';
            }
        }
        if(count > 1 && key[i] != '0')
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }
    char alpha[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    string P_text = get_string("Plaintext: ");
    int n = strlen(P_text);
    char C_text[n+1];
    for(int i = 0; i < n;i++)
    {
        if (isupper(P_text[i]) != 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (P_text[i] == alpha[j])
                {
                    C_text[i] = key[j];
                    break;
                }
            }
        }
        else if (islower(P_text[i]) != 0)
        {
            for (int j = 0; j < strlen(alpha); j++)
            {
                if (P_text[i] == tolower(alpha[j]))
                {
                    C_text[i] = tolower(key[j]);
                    break;
                }
            }
        }
        else
        {
            C_text[i] = P_text[i];
        }
    }
        C_text[n] = '\0';
        printf("ciphertext: %s\n", C_text);
        return 0;
}