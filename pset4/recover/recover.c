#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image \n");
        return 1 ;
    }
    char *card = argv[1];
    FILE *infile = fopen(card, "r");
    if (card == NULL)
    {
        fprintf(stderr, "Could not open %s\n", card);
        return 2;
    }
    
    BYTE buffer[512];
    int count = 0 ; 
    FILE *outfile = NULL ;
    char filename[8];
    
    
    while (fread(&buffer, 512, 1, infile))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count != 0)
            {
                fclose(outfile);
            }
            
            sprintf(filename, "%03i.jpg", count);
            outfile = fopen(filename, "w");
            count++;
            
        }
        
        if (outfile != NULL)
        {
            fwrite(&buffer, 512, 1, outfile);
        }
    }
    fclose(infile);
    fclose(outfile);
    return 0;
}