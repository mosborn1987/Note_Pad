#ifndef DATA_HANDLER_H_INCLUDED
#define DATA_HANDLER_H_INCLUDED

#include <file_handler.h>

// Temp Data Buffers
char temp_data_buffer[256];
char temp_data_buffer_2[256];

// Character Sets
char number_set[] ="1234567890";
char abc_set[] = "abcdefghijklmnopqrstuvwxyz";
char ABC_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char special_char_set[] = "(\/).";
char char_collection[256];

// These are the two functions that are needed.
int get_append_after_specified_string(char *dest, char *src, char *string_array);
int get_first_string(char *dst, char *srd, char *char_set);


// This function will retrieve all the remaining/appending string
// following a specified string.
int get_append_after_specified_string(char *dest, char *src, char *string_array)
{
    // Get length of src
    int src_length = strlen(src);

    // Get Length of string_array
    int str_length = strlen(string_array);

    // Create a pointer to location
    char *p_string;
    p_string = strstr(src, string_array);

    // If string was not found
    if(p_string == NULL)
    {
        return NULL;
    }

    else if(p_string !=NULL)
    {
        strncpy(dest, p_string + str_length, src_length - str_length);
        return 1;
    }
}


int get_WR_number(char *mm_buffer)
{
    // Rewind fp_ORIGINAL
    rewind(fp_ORIGINAL);

    // Local Buffer
    char Local_buffer[256];

    // Read next line of text
    get_next_line(fp_ORIGINAL, Local_buffer);

    int test_char = 0;
    // Retrieve WR Number
    test_char = get_append_after_specified_string(mm_buffer, Local_buffer, "WR #: ");

    return 0;

}

#endif // DATA_HANDLER_H_INCLUDED
