#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


bool check_valid_alpha(string s);
bool check_26(string s);
bool check_rep(string s);
char key(string s);
string ciphertext(string keytext, string ptext);


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n") ;
        return 1 ;
    }
    else if (!check_26(argv[1]))
    {
        printf("Key must contain 26 characters.\n") ;
        return 1 ;
    }
    else if (!check_valid_alpha(argv[1]))
    {
        printf("Usage: ./substitution key\n") ;
        return 1 ;
    }
    else if (!check_rep(argv[1]))
    {
        printf("The letters can't be repeated!\n");
        return 1 ;
    }


    string ptext = get_string("plaintext: ");
    printf("ciphertext: ") ;
    string s = ciphertext(argv[1], ptext);
    printf("%s\n", s);
    return 0 ;

}


bool check_valid_alpha(string s)
{
    int n = strlen(s);
    for(int i = 0 ; i < n ; i++)
    {
       if(!isalpha(s[i]))
       {
           return false ;
       }
    }
    return true ;
}

bool check_26(string s)
{
    int n = strlen(s);
    if(n != 26)
    {
        return false;
    }
    return true;
}


bool check_rep(string s )
{
    int num[26] ;
    for (int i = 0 ; i < 26 ; i++)
    {
        num[i] = 0 ;
    }
    for (int j = 0 ; j < 26 ; j++)
    {

        int number = toupper(s[j]) - 'A';
        if (num[number] > 0)
        {
            return false;
        }
        num[number]++ ;
    }
    return true;
}


string ciphertext(string keytext, string ptext)
{
    int len = strlen(ptext);
    string cipher = ptext ;

    for (int i = 0 ; i < len ; i++)
    {
       if (isupper(ptext[i]))
       {
          int position = ptext[i] -'A' ;
          cipher[i] = toupper(keytext[position]) ;
       }
       else if (islower(ptext[i]))
       {
          int position = ptext[i] -'a' ;
          cipher[i] = tolower(keytext[position]) ;
       }
       else if (!isalpha(ptext[i]))
       {
           cipher[i] = ptext[i];
       }

    }
    return cipher;
}