#include <math.h>
#include <cs50.h>
#include <stdio.h>


int length(long n) ;
int ind_sum(int n) ;
int checksum_alg(int n) ;
int first2digits(long n) ;
int firstdigit(long n) ;



int main()
{
  //*****************//
    long digit ;
    int i, j ;
    int digit2 ;
    long card ;
    int sum1 = 0 ;
    int sum2 = 0 ;
    int sumeven ;
    int sumodd = 0;
    int digit0 ;
    int total ;



    //***************************// to get input from user
    do
    {
        card = get_long("Credit card number : ");
    }
    while (card < 0);  //pow(10,12)




//********************************************// the checksum algorithm
   for(i = 0 ; i < length(card) -1 ; i+=2)
   {
       digit = (card % (long)pow(10,i+2) - card % (long)pow(10,i+1))/ (long)pow(10,i+1);
       digit2 = digit * 2 ;
       if(digit2 <= 9){
           sum1 = sum1 + digit2 ;
       }
       else
       {
           sum2 = sum2 + ind_sum(digit2) ;
       }

   }
   sumeven = sum1 + sum2 ;
   //printf("\n %i \n ", sumeven ) ;

  //Sum of odd place digit

   for(j = 0 ; j < length(card) ; j+=2)
   {
       digit0 = (card % (long)pow(10,j+1) - card % (long)pow(10,j))/ (long)pow(10,j);
       sumodd = sumodd + digit0 ;
   }
   //printf("\n %i \n ", sumodd ) ;

    total = sumodd + sumeven ;
    //printf("\n %i \n ",total);

   //**************************************************// check if modulo 10 = zero
   //printf("\n %i \n ",length(card));
   if(total % 10 !=0)
   {
       printf("INVALID\n");
   }
   else
   {
        if(length(card) != 13 && length(card) != 15 && length(card) != 16 )
        {
             printf("INVALID\n") ;

        }
        else
        {
            if(length(card) == 15 && (first2digits(card) == 34 || first2digits(card)== 37 ))
            {
                printf("AMEX\n");
            }
            else if (length(card) == 16 && (first2digits(card) == 51 || first2digits(card) == 52 || first2digits(card) == 53 || first2digits(card) == 54 || first2digits(card) == 55 ))
            {
                printf("MASTERCARD\n") ;
            }
            else if((length(card) == 13 || length(card) == 16) && firstdigit(card) == 4)
            {
                printf("VISA\n") ;
            }
            else
            {
                printf("INVALID\n") ;
            }
        }
   }




}



//MY FUNCTIONS
int length(long n)
{
    int i = 0 ;
    while(n != 0)
    {
        n = n/10 ;
        i++ ;
    }
    return i ;
}

int ind_sum(int n)
{
    int sum = 0 ;
    while(n != 0)
    {
        sum = sum + n % 10 ;
        n = n/10 ;
    }
    return sum ;
}

int first2digits(long n)
{
    long i = n ;
    while (i >= 100)
    {
        i /= 10;
    }

    return i;
}

int firstdigit(long n)
{
    long i = n ;
    while (i >= 10)
    {
        i /= 10;
    }

    return i;
}