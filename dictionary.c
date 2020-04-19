// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"
#define MULTIPLIER (37)

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned long N = 65536;

// Hash table
node *table[N];

// Word count
unsigned int word_count;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Convert whole word to lowercase
    char *low_word = malloc(sizeof(word));
    for(int i = 0, j = strlen(word); i < j + 1; i++)
    {
        low_word[i] = tolower(word[i]);
    }

    int h = hash(low_word);
    free(low_word);
    for (node *tmp = table[h]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(word, tmp->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Hashtable copied from https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/
    // Also inspired by http://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
        hash = (hash << 2) ^ word[i];
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        return false;
    }
    // Create a word
    char word[LENGTH + 1];
    unsigned int h;
    word_count = 0;
    // Read strings from a file one at a time
    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocate memory for a node with new word and copy it there
        node *n = malloc(sizeof(node));
        if (!n)
        {
            return false;
        }
        strcpy(n->word, word);
        // Hash each word
        h = hash(word);
        // Paste node into Hash Table
        n->next = table[h];
        table[h] = n;
        // Count the words loaded into dictionary
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *cursor = NULL;
    node *tmp = NULL;
    for(int h = 0; h < N; h++)
    {
        cursor = table[h];
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        free(cursor);

        if (h == N - 1)
        {
            return true;
        }
    }
    return false;
}
