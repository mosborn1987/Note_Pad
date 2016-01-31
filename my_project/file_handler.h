#ifndef FILE_HANDLER_H_INCLUDED
#define FILE_HANDLER_H_INCLUDED

// Included Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Array Declaration
static char root_path[256] = "C:/Users/Mario Osborn/Desktop/DUKE_FILES/";
char WR_Number[50];

// Original Folder and Path Name
static char Original_Folder[256] = "Originals/";
char Original_file_path[256];

// Formatted Folder and Path Name
static char Formatted_Folder[256] = "Formatted/";
char Formatted_file_path[256];

// Function Prototypes
char transfer_buffer[256];

// Original WR File
int OPEN_ORIGINAL(void);
int CLOSE_ORIGINAL(void);
int Read_ORIGINAL(int chars_to_read);
FILE *fp_ORIGINAL;

// Formatted WR File
int CREAT_FORMATTED(void);
int CLOSE_FORMATTED(void);
int WRITE_FORMATTED(void);
FILE *fp_FORMATTED;

// Stitch File Location
void stitch_file_location(char *buffer_array, char *folder, char *file);
void stitch_file_directories();



// Function Bodies

// Write Formatted
int WRITE_FORMATTED(void)
{
    fwrite(transfer_buffer, 1, strlen(transfer_buffer), fp_FORMATTED);
    return 0;
}

// Close Formatted
int CLOSE_FORMATTED(void)
{
    // Close Formatted file pointer
    fclose(fp_FORMATTED);
    return 0;
}

// Formatted Functions
int CREAT_FORMATTED(void)
{
    // Create a new folder that will delete
    // the contents of a file with the same
    // name if it already exists.
    fp_FORMATTED = fopen(Formatted_file_path, "w");

    // Make sure file was opened correctly
    if(fp_FORMATTED == NULL)
    {
        return -1;
    }

    // If opened correctly
    return 0;

}

// Open_Original: WR File
int OPEN_ORIGINAL()
{
    // Open File
    fp_ORIGINAL = fopen (Original_file_path, "r");
    if(fp_ORIGINAL == NULL)
    {
       return 1;
    }

    // If opened correctly
    return 0;
}

int CLOSE_ORIGINAL()
{
    // Close Original file pointer
    fclose(fp_ORIGINAL);
    return 0;
}


int Read_ORIGINAL(int chars_to_read)
{
   fread(transfer_buffer, 1, chars_to_read , fp_ORIGINAL);

//   printf("\n\n%s", transfer_buffer);

}


// Stitch both the Original File location and the Formatted Directories.
void stitch_file_directories()
{
    // Stitch Original
    stitch_file_location(Original_file_path, Original_Folder, WR_Number);

    // Stitch Formatted
    stitch_file_location(Formatted_file_path, Formatted_Folder, WR_Number);

    // Original Folder and Path Name
}


// Stitch File Location
void stitch_file_location(char *buffer_array, char *folder, char *file)
{
    // Clear buffer
    buffer_array[0] = '\0';

    // stitch the root
    strcat(buffer_array, root_path);

    // Stitch the Folder
    strcat(buffer_array, folder);

    // stitch the file
    strcat(buffer_array, file);

    // stitch the '.txt'.
    strcat(buffer_array, ".txt");

}


#endif // FILE_HANDLER_H_INCLUDED
