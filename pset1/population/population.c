#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start, end ;
    int n = 0;
    int num ;
    // TODO: Prompt for start size
   do
   {
        start = get_int("Start size : ");
   }
   while (start < 9);
   
    // TODO: Prompt for end size
    do
    {
        end = get_int("End size : ");
    }
    while(end < start);
    // TODO: Calculate number of years until we reach threshold
    
    while(start < end)
    {
        start = start + (start/3) - (start/4) ; 
        num = n + 1 ;
        n++;
    }
    
    
    
    
    // TODO: Print number of years
    printf("Years: %i \n", num);
    
}