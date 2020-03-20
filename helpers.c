#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed;
    float sepiaGreen;
    float sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Allocate memory for temp image
    RGBTRIPLE(*tempimage)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (tempimage == NULL)
    {
        fprintf(stderr, "Not enough memory to store temp image.\n");
        return;
    }

    // Convert each row for temp image
    int k = 0;
    int j;
    do
    {
        j = width - 1;
        do
        {
            for (int i = 0; i < width; i++)
            {
                tempimage[k][j].rgbtRed = image[k][i].rgbtRed;
                tempimage[k][j].rgbtGreen = image[k][i].rgbtGreen;
                tempimage[k][j].rgbtBlue = image[k][i].rgbtBlue;
                j--;
            }
        }
        while (j >= 0);
        k++;
    }
    while (k < height);

    // Get temp image into old image
    for (int i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tempimage[i][j].rgbtRed;
            image[i][j].rgbtGreen = tempimage[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tempimage[i][j].rgbtBlue;
        }
    }

    // free the space from temp image
    free(tempimage);
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Allocate memory for temp image
    RGBTRIPLE(*tempimage)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (tempimage == NULL)
    {
        fprintf(stderr, "Not enough memory to store temp image.\n");
        return;
    }

    int sumRed;
    int sumGreen;
    int sumBlue;
    int counter;
    float averageRed;
    float averageGreen;
    float averageBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            counter = 0;
            sumRed = 0;
            averageRed = 0;
            sumGreen = 0;
            averageGreen = 0;
            sumBlue = 0;
            averageBlue = 0;
            // Taking average with omitting cells less than 0 or greater than width/height
            for (int k = i - 1; k < i + 2; k++)
            {
                if (k < 0 || k > height - 1)
                {
                    continue;
                }

                for (int l = j - 1; l < j + 2; l++)
                {
                    if (l < 0 || l > width - 1)
                    {
                        continue;
                    }

                    sumRed += image[k][l].rgbtRed;
                    sumGreen += image[k][l].rgbtGreen;
                    sumBlue += image[k][l].rgbtBlue;

                    counter ++;
                }
            }
            averageRed = round(sumRed / counter);
            averageGreen = round(sumGreen / counter);
            averageBlue = round(sumBlue / counter);

            tempimage[i][j].rgbtRed = averageRed;
            tempimage[i][j].rgbtGreen = averageGreen;
            tempimage[i][j].rgbtBlue = averageBlue;
        }
    }

    // Get temp image into old image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tempimage[i][j].rgbtRed;
            image[i][j].rgbtGreen = tempimage[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tempimage[i][j].rgbtBlue;
        }
    }

    // free the space from temp image
    free(tempimage);
    return;
}
