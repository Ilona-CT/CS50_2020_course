#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    float L = ((float)count_letters(text)/(float)count_words(text))*100;
    float S = ((float)count_sentences(text)/(float)count_words(text))*100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}


// counting letters
int count_letters(string text)
{
    int i, letters = 0, n = strlen(text);
    for(i = 0; i < n; i++)
    {
        if(isalpha(text[i]))
        {
           letters++;
        }
    }
    return letters;
}

// counting words
int count_words(string text)
{
    int i, words = 0, n = strlen(text);
    for(i = 0; i < n; i++)
    {
        if(text[i] == ' ' || text[i+1] == '\0')
        {
           words++;
        }
    }
    return words;
}

// counting sentences
int count_sentences(string text)
{
    int i, sentences = 0, n = strlen(text);
    for(i = 0; i < n; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
           sentences++;
        }
    }
    return sentences;
}