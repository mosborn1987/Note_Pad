#ifndef DATA_HANDLER_H_INCLUDED
#define DATA_HANDLER_H_INCLUDED

#include <file_handler.h>

int get_WR_number(char *mm_buffer);
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
    char n_set[] ="1234567890";
    int wr_string_span = strcspn(mm_buffer, n_set);

    // Copy over the characters
    strncpy(mm_buffer, p_char+test_string_length, line_length-wr_string_span);
    mm_buffer[line_length-wr_string_span] = '\0';

    return 0;

}































//    for(temp_i =)

//    strncpy(temp_data_buffer, p_char, p_char+strlen(test_string));

//    printf("\n Did it work? %s",temp_data_buffer);



//
//
//    int main ()
//{
//  char str[] ="This is a simple string";
//  char * pch;
//  pch = strstr (str,"simple");
//  strncpy (pch,"sample",6);
//  puts (str);
//  return 0;
//}

//
//
//    printf("Material Read: %s\n", transfer_buffer);
//
//    // Locate string in transfer_buffer
//    char *string_location;
//    string_location = strstr(transfer_buffer, "test_string");
//
//    printf("\nString Location: %d", string_location);
//
//    // Calculate String location
//    string_location = string_location - transfer_buffer;
//    printf("\nString Offset: %c", string_location);

//    // Beginning of file
//    fseek(fp_ORIGINAL, string_location, SEEK_SET);
//
//    // Read
//    fread(transfer_buffer, 1, 10, fp_ORIGINAL);
//
//    // Print String
//    printf("\nRead Material: %s", transfer_buffer);

//
///* strstr example */
//#include <stdio.h>
//#include <string.h>
//
//int main ()
//{
//  char str[] ="This is a simple string";
//  char * pch;
//  pch = strstr (str,"simple");
//  strncpy (pch,"sample",6);
//  puts (str);
//  return 0;
//}



//    // Find First Char
//    char_position = strstr(fp_ORIGINAL, test_string);
//
//    printf("\nChar_Position = %d", char_position);
//
//
//
//    // Rewind the fp position
//    rewind(fp_ORIGINAL);
//
//    // Get Current Location
//    fp_position = ftell(fp_ORIGINAL);
//
//    // Fseek the location of the current fp
//    fseek(fp_ORIGINAL, (fp_position - char_position), SEEK_SET);
//
//    // Read String
//    fread(transfer_buffer, 1, strlen(test_string), fp_ORIGINAL);
//
//    // Print Read material
//    printf("\nData Read: %s", transfer_buffer);

//}




#endif // DATA_HANDLER_H_INCLUDED
