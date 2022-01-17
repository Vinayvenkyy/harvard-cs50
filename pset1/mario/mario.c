#include <stdio.h>
#include <cs50.h>

int main(void){
    int h,i,j,k,k1 ;
    do{
        h = get_int("Height : ");
    }while(h < 1 || h > 8);

    for(i = 0 ; i < h ; i++)
    {
        for(j = 0 ; j < h-i-1 ; j++)
        {
            printf(" ");
        }
        for(k = 0 ; k <= i ; k++)
        {
            printf("#");
        }

        printf("  ") ;

        for(k1 = 0 ; k1 <= i ; k1++)
        {
            printf("#");
        }
       

        printf("\n");
    }
}