#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins !\n") ;
    }
    if (score1 < score2)
    {
        printf("Player 2 wins !\n") ;
    }
    if (score1 == score2)
    {
        printf("Tie !\n") ;
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    int sum = 0 ;
    char alpha1[26] ;
    char alpha2[26] ;

    for(int i = 0 ; i < 26 ; i++)
    {
        alpha1[i] = 'a' + i ;
    }

    for(int l = 0 ; l < 26 ; l++)
    {
        alpha2[l] = 'A' + l ;
    }


    for(int j = 0 ; j < 26 ; j++)
    {
        for(int k = 0 ; k < 26 ; k++)
        {
            if(word[j] == alpha1[k])
            {
                sum = sum + POINTS[k];
            }
            else if(word[j] == alpha2[k])
            {
                sum = sum + POINTS[k];
            }
        }
    }


    return sum ;

}