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

    // Free the space from temp image
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
    float counter;
    float averageRed;
    float averageGreen;
    float averageBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            counter = 0.0;
            sumRed = 0;
            averageRed = 0.0;
            sumGreen = 0;
            averageGreen = 0.0;
            sumBlue = 0;
            averageBlue = 0.0;
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Allocate memory for temp image
    RGBTRIPLE(*tempimage)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (tempimage == NULL)
    {
        fprintf(stderr, "Not enough memory to store temp image.\n");
        return;
    }

    // Create Gx Matrix
    float (*GxMatrix)[3] = calloc(3, 3 * sizeof(float));
    if (GxMatrix == NULL)
    {
        fprintf(stderr, "Not enough memory to store GxMatrix.\n");
        return;
    }
    // Assign values to GxMatrix
    GxMatrix[0][0] = -1;
    GxMatrix[0][1] = 0;
    GxMatrix[0][2] = 1;
    GxMatrix[1][0] = -2;
    GxMatrix[1][1] = 0;
    GxMatrix[1][2] = 2;
    GxMatrix[2][0] = -1;
    GxMatrix[2][1] = 0;
    GxMatrix[2][2] = 1;

    //Create Gy Matrix
    float (*GyMatrix)[3] = calloc(3, 3 * sizeof(float));
    if (GyMatrix == NULL)
    {
        fprintf(stderr, "Not enough memory to store GyMatrix.\n");
        return;
    }
    // Assign values to GyMatrix
    GyMatrix[0][0] = -1;
    GyMatrix[0][1] = -2;
    GyMatrix[0][2] = -1;
    GyMatrix[1][0] = 0;
    GyMatrix[1][1] = 0;
    GyMatrix[1][2] = 0;
    GyMatrix[2][0] = 1;
    GyMatrix[2][1] = 2;
    GyMatrix[2][2] = 1;

    // create floats variables being used
    float sumRedGx;
    float sumGreenGx;
    float sumBlueGx;
    float sumRedGy;
    float sumGreenGy;
    float sumBlueGy;
    float SobelRed;
    float SobelGreen;
    float SobelBlue;
    float TotalRed;
    float TotalGreen;
    float TotalBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sumRedGx = 0.0;
            sumRedGy = 0.0;
            sumGreenGx = 0.0;
            sumGreenGy = 0.0;
            sumBlueGx = 0.0;
            sumBlueGy = 0.0;
            TotalRed = 0.0;
            TotalGreen = 0.0;
            TotalBlue = 0.0;
            SobelRed = 0.0;
            SobelGreen = 0.0;
            SobelBlue = 0.0;
            // Summing Gx and Gy values
            for (int k = i - 1, a = 0; k < i + 2 && a < 3; k++, a++)
            {
                if (k < 0 || k > height - 1)
                {
                    continue;
                }

                for (int l = j - 1, b = 0; l < j + 2 && b < 3; l++, b++)
                {
                    if (l < 0 || l > width - 1)
                    {
                        continue;
                    }

                    sumRedGx += image[k][l].rgbtRed * GxMatrix[a][b];
                    sumGreenGx += image[k][l].rgbtGreen * GxMatrix[a][b];
                    sumBlueGx += image[k][l].rgbtBlue * GxMatrix[a][b];

                    sumRedGy += image[k][l].rgbtRed * GyMatrix[a][b];
                    sumGreenGy += image[k][l].rgbtGreen * GyMatrix[a][b];
                    sumBlueGy += image[k][l].rgbtBlue * GyMatrix[a][b];
                }
            }

            // Multiply the Sums
            TotalRed = sqrtf(powf(sumRedGx, 2) + powf(sumRedGy, 2));
            TotalGreen = sqrtf(powf(sumGreenGx, 2) + powf(sumGreenGy, 2));
            TotalBlue = sqrtf(powf(sumBlueGx, 2) + powf(sumBlueGy, 2));

            //Round the Sobels Algorithms up
            SobelRed = round(TotalRed);
            SobelGreen = round(TotalGreen);
            SobelBlue = round(TotalBlue);

            if (SobelRed > 255)
            {
                tempimage[i][j].rgbtRed = 255;
            }
            else
            {
                tempimage[i][j].rgbtRed = SobelRed;
            }

            if (SobelGreen > 255)
            {
                tempimage[i][j].rgbtGreen = 255;
            }
            else
            {
                tempimage[i][j].rgbtGreen = SobelGreen;
            }

            if (SobelBlue > 255)
            {
                tempimage[i][j].rgbtBlue = 255;
            }
            else
            {
                tempimage[i][j].rgbtBlue = SobelBlue;
            }
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

    // free the space from temp image, GxMatrix and GyMatrix
    free(tempimage);
    free(GxMatrix);
    free(GyMatrix);
    return;
}
