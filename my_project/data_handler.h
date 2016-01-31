#ifndef DATA_HANDLER_H_INCLUDED
#define DATA_HANDLER_H_INCLUDED

#include <data_handler.h>

char test_string[256] = "WR #: ";

long char_position = 0;

void find_string();
void find_string()
{
    // Find First Char
    char_position = strstr(fp_ORIGINAL, test_string);

    // Read String
    fread(transfer_buffer, 1, strlen(test_string), fp_ORIGINAL);

    // Print Read material
    printf("%s", transfer_buffer);


    // Test the following string against a passed value
}




#endif // DATA_HANDLER_H_INCLUDED
