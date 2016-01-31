#ifndef DATA_HANDLER_H_INCLUDED
#define DATA_HANDLER_H_INCLUDED

#include <file_handler.h>

char test_string[256] = "WR";

long char_position = 5;
long fp_position = 0;

void read_line(void);
void read_line(void)
{



}

void find_string();
void find_string()
{
    // Find First Char
    char_position = strstr(fp_ORIGINAL, test_string);

    printf("\nChar_Position = %d", char_position);



    // Rewind the fp position
    rewind(fp_ORIGINAL);

    // Get Current Location
    fp_position = ftell(fp_ORIGINAL);

    // Fseek the location of the current fp
    fseek(fp_ORIGINAL, (fp_position - char_position), SEEK_SET);

    // Read String
    fread(transfer_buffer, 1, strlen(test_string), fp_ORIGINAL);

    // Print Read material
    printf("\nData Read: %s", transfer_buffer);

}




#endif // DATA_HANDLER_H_INCLUDED
