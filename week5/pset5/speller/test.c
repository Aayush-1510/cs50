#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>


bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *dict_pointer = fopen(dictionary, "r");
    // Check if null
    if (dictionary == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }
    // Initialise word array
    char next_word[LENGTH + 1];
    // Read strings from file one at a time
    while (fscanf(dict_pointer, "%s", next_word) != EOF)
    {
        // Create new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        // copy word into node using strcopy
        strcpy(n->word, next_word);
        // Hash word to obtain hash value
        int hash_value = hash(next_word);
        // Insert node into hash table at that location
        n->next = table[hash_value];
        table[hash_value] = n;
        dict_size++;
    }
    // Close file
    fclose(dict_pointer);
return true;
}
