#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int count_letters(string x) ;
int count_words(string x) ;
int count_sentence(string x);


int main(void)
{
    string text = get_string("Text: ");
    int letter = count_letters(text);
    int word = count_words(text);
    int sentence = count_sentence(text);
    
    float L = (letter / (float)word)*100;
    float S = (sentence / (float)word)*100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    
    if(index >= 1 && index <16)
    {
        printf("Grade %i\n", index);
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    
}

//My Functions

int count_letters(string x)
{
    int sum = 0 ;
    int n = strlen(x);
    for (int i = 0 ; i < n ; i++)
    {
        if ((x[i] >= 'a' && x[i] <= 'z') || (x[i] >= 'A' && x[i] <= 'Z'))
        {
            sum = sum + 1 ;
        }
    }
    return sum ;
}

int count_words(string x)
{
    int sum = 1 ;
    int n = strlen(x);
    for (int i = 0 ; i < n ; i++)
    {
        if (x[i] == ' ')
        {
            sum = sum +1 ;
        }
    }
    return sum ;
}

int count_sentence(string x)
{
    int sum = 0 ;
    int n = strlen(x);
    
    for (int i = 0 ; i < n ; i++)
    {
        if (x[i] == '.' || x[i] == '!' || x[i] == '?')
        {
            sum = sum + 1 ;
        }
    }
    return sum ;
}