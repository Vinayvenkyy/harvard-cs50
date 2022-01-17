#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool check_valid(string s);
void cipher(string s, int k);


int main(int argc, string argv[])
{
    if (argc != 2 || !check_valid(argv[1]))
    {
        printf("Usage: ./caesar key\n") ;
        return 1 ;
    }
    
    int k = atoi(argv[1]);
    string text = get_string("plaintext:  ") ;
    
    printf("ciphertext: ");
    cipher( text , k);
    
    
}


bool check_valid(string s)
{
    int n = strlen(s);
    for (int i = 0 ; i < n ; i++)
    {
        if(!isdigit(s[i]))
        {
            return false ;
        }
    }
    return true;
}


void cipher(string s, int k)
{
    int n = strlen(s);
    
    
    for (int i = 0 ; i < n ; i++)
    {
       if (isalpha(s[i]))
       {
           if (islower(s[i]))
           {
               printf("%c", ((s[i] - 'a' + k) % 26) + 'a') ; 
               
           }
           if (isupper(s[i]))
           {
               printf("%c", ((s[i] - 'A' + k) % 26)  + 'A') ;
               
           }
       }
       else 
       {
           printf("%c" , s[i]);
       }
    }
    printf("\n");
}