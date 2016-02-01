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

/* Goes to the next collection(not separated by commas or '\n') of characters*/
int get_next_string_apend(char *dst_array, char *src_array, char *char_set);
int get_next_string(char *dst_array, char *src_array, char *char_set);

// Seeks out a particular string
int get_string_append(char *dst_array, char *src_array);
int get_string();

int get_WR_number(char *mm_buffer);

// Function Bodies
int get_next_string_apend(char *dst_array, char *src_array, char *char_set)
{

}

int get_WR_number(char *mm_buffer)
{
    // Rewind fp_ORIGINAL
    rewind(fp_ORIGINAL);

    // Read first line of code
    int line_length = Get_Next_Line_ORIGINAL(mm_buffer);

    // Test String
    char test_string[256] = "WR #: ";
    int test_string_length = strlen(test_string);

    // Buffer
    char temp_data_buffer[50];

    // Point to location of string
    char *p_char;
    p_char = strstr(mm_buffer, test_string);

    // String Span
    int wr_string_span = strcspn(mm_buffer, number_set);

    // Copy over the characters
    strncpy(mm_buffer, p_char+test_string_length, line_length-wr_string_span);
    mm_buffer[line_length-wr_string_span] = '\0';

    return 0;

}


#endif // DATA_HANDLER_H_INCLUDED
