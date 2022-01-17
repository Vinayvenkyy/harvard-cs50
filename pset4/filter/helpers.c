#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg ;

    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/(float)3) ;
            image[i][j].rgbtBlue  = avg ;
            image[i][j].rgbtGreen = avg ;
            image[i][j].rgbtRed = avg ;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width] ;
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            temp[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            temp[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            temp[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
        }
    }
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen ;
            image[i][j].rgbtRed = temp[i][j].rgbtRed ;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            temp[i][j].rgbtRed = image[i][j].rgbtRed;
            temp[i][j].rgbtGreen = image[i][j].rgbtGreen;
            temp[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            int counter = 0 ;
            int sumRed, sumGreen, sumBlue ;
            sumRed = sumGreen = sumBlue = 0 ;

            for (int x = -1 ; x < 2 ; x++)
            {
                for (int y = -1 ; y < 2 ; y++)
                {
                    int x_pos = i + x;
                    int y_pos = j +y;

                    if (x_pos < 0 || y_pos < 0 || x_pos >= height || y_pos >= width)
                    {
                        continue ;
                    }

                    sumRed = sumRed + temp[x_pos][y_pos].rgbtRed ;
                    sumGreen = sumGreen + temp[x_pos][y_pos].rgbtGreen;
                    sumBlue = sumBlue + temp[x_pos][y_pos].rgbtBlue;
                    counter++ ;
                }
            }

            image[i][j].rgbtRed = round((float) sumRed / counter) ;
            image[i][j].rgbtGreen = round((float) sumGreen / counter) ;
            image[i][j].rgbtBlue = round((float) sumBlue / counter) ;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create temp array
    RGBTRIPLE temp[height][width];
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            temp[i][j].rgbtRed = image[i][j].rgbtRed;
            temp[i][j].rgbtGreen = image[i][j].rgbtGreen;
            temp[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    
    // Initialise Sobel arrays
    int arrGx[9] = {-1, 0, 1 , -2, 0, 2, -1, 0, 1};
    int arrGy[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            float GxR, GxG , GxB, GyR, GyG , GyB ;
            GxR = GxG = GxB = GyR = GyG = GyB = 0 ;
            int counter = -1 ; 
            
            for (int x = -1 ; x < 2 ; x++)
            {
                for (int y = -1 ; y < 2 ; y++)
                {
                    int x_pos = i + x;
                    int y_pos = j +y;
                    
                    if (x_pos < 0 || y_pos < 0 || x_pos >= height || y_pos >= width)
                    {
                        counter++ ;
                        
                    }
                    else
                    {
                        counter++ ; 
                        
                        GxR = GxR + arrGx[counter]*temp[x_pos][y_pos].rgbtRed ;
                        GxG = GxG + arrGx[counter]*temp[x_pos][y_pos].rgbtGreen;
                        GxB = GxB + arrGx[counter]*temp[x_pos][y_pos].rgbtBlue;
    
                        GyR = GyR + arrGy[counter]*temp[x_pos][y_pos].rgbtRed ;
                        GyG = GyG + arrGy[counter]*temp[x_pos][y_pos].rgbtGreen;
                        GyB = GyB + arrGy[counter]*temp[x_pos][y_pos].rgbtBlue;
                    }
                }
            }
            int R = round(sqrt(GxR*GxR + GyR*GyR));
            int G = round(sqrt(GxG*GxG + GyG*GyG));
            int B = round(sqrt(GxB*GxB + GyB*GyB));

            if (R > 255)
            {
                R = 255 ;
            }
            if (G > 255)
            {
                G = 255 ;
            }
            if (B > 255)
            {
                B = 255 ;
            }

            image[i][j].rgbtRed = R ;
            image[i][j].rgbtGreen = G ;
            image[i][j].rgbtBlue = B ;
        }
    }
    return;
}


