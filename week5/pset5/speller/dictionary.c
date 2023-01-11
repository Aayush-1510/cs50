// Implements a dictionary's functionality

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int dict_size = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashcode = hash(word);
    node *tmp = table[hashcode];

    while(tmp != NULL)
    {
        if(strcasecmp(word,tmp->word) == 0)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

// Hashes word to a number
/**
unsigned int hash(const char *word)
{
    // Function should take a string and return an index
    // This hash function adds the ASCII values of all characters in     the word together
    long sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}
*/

unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    char tmp = toupper(word[0]);
    int hashcode = tmp - 65;
    return hashcode;
}

// Loads dictionary into memory, returning true if successful, else false

bool load(const char *dictionary)
{
    // Open dictionary file and check for exeption
    FILE *Dict = fopen(dictionary, "r");
    if(Dict == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(Dict, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            return false;
        }
        strcpy(n->word,word);
        int hashcode = hash(word);
        n->next = table[hashcode];
        table[hashcode] = n;
        dict_size++;
    }
    fclose(Dict);
    return true;
}
// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        node *tmp = cursor;

        while(cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    if (cursor == NULL && i == (N - 1))
        {
            return true;
        }
    }
    return false;
}
