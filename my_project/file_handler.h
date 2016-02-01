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

// Original WR File
int OPEN_ORIGINAL(void);
int CLOSE_ORIGINAL(void);
int Get_Next_Line_ORIGINAL(char *m_buffer);
int Read_ORIGINAL(char *m_Array, int chars_to_read);
FILE *fp_ORIGINAL;

// Formatted WR File
int CREAT_FORMATTED(void);
int CLOSE_FORMATTED(void);
int WRITE_FORMATTED(char *m_array);
FILE *fp_FORMATTED;

// Stitch File Location
void stitch_file_location(char *buffer_array, char *folder, char *file);
void stitch_file_directories();

// get_next_line: Retrieves the characters beginning at the original location of the fp
//                and ending at the '\n' char.
int get_next_line(FILE *fp, char *m_buffer_array);

int get_next_line(FILE *fp, char *m_buffer_array)
{
    // Local Variable(s)
    char temp_c = 'A';
    unsigned int i=0;

    while((temp_c!='\n')&&(temp_c!=EOF))
    {
        temp_c = fgetc(fp);
        m_buffer_array[i] = temp_c;
        i++;
    }
    i--;
    m_buffer_array[i] = '\0';
    return i;
}

// Function Bodies

// Write Formatted
int WRITE_FORMATTED(char *m_array)
{
    fwrite(m_array, 1, strlen(m_array), fp_FORMATTED);
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
int OPEN_ORIGINAL(void)
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

int Get_Next_Line_ORIGINAL(char *m_buffer)
{
    return get_next_line(fp_ORIGINAL, m_buffer);
}

int CLOSE_ORIGINAL()
{
    // Close Original file pointer
    fclose(fp_ORIGINAL);
    return 0;
}


int Read_ORIGINAL(char *m_Array, int chars_to_read)
{
   fread(m_Array, 1, chars_to_read , fp_ORIGINAL);

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
