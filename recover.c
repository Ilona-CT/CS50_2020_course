#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

// Declare 1 byte size
typedef uint8_t BYTE;
// Declare whole block size
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Accept 1 argument only
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    // Accept only given name of forensic's image
    if (strcmp(argv[1], "card.raw") != 0)
    {
        printf("Forensic's image name incorrect");
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");

    // Check if it has actually opened (if it is NULL - error occured)
    if (!file)
    {
        printf("Cannot open the file");
        return 1;
    }

    // Create block of 512 BYTEs
    unsigned char block[BLOCK_SIZE];
    // Create a photo counter variable
    int photo_counter = 0;
    // Create a photo name
    char photo_name[8];
    // Create a file for a photo
    FILE *photo = NULL;

    // Start looping through the file until it ends
    while (fread(block, BLOCK_SIZE, 1, file) == 1)
    {
        // Create a bool value for photo begining
        bool found_photo = block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0;

        // When new photo is found -> close current file and name, increase found photo no and open new file at its name
        if (found_photo == true)
        {
            if (photo_counter > 0)
            {
                fclose(photo);
            }
            // Escape with success when already 50 photos found
            if (photo_counter == 50)
            {
                printf("50 pics found!");
                return 0;
            }
            sprintf(photo_name, "%03i.jpg", photo_counter);
            photo = fopen(photo_name, "w");
            photo_counter++;
        }

        // When new file is opened correctly we can safely write into it
        if (photo != NULL)
        {
            fwrite(&block, BLOCK_SIZE, 1, photo);
        }
    }
    fclose(file);
}
