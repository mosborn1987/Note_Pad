#ifndef DATA_HANDLER_H_INCLUDED
#define DATA_HANDLER_H_INCLUDED

#include <file_handler.h>


char temp_data_holder[256];

long char_position = 5;
long fp_position = 0;

// get_next_line: Retrieves the characters beginning at the original location of the fp
//                and ending at the '\n' char.
int get_next_line(FILE *fp);
int get_next_line(FILE *fp)
{
    // Local Variable(s)
    char temp_c = 'A';
    unsigned int i=0;

    while((temp_c!='\n')&&(temp_c!=EOF))
    {
        temp_c = fgetc(fp);
        transfer_buffer[i] = temp_c;
        i++;
    }
    i--;
    transfer_buffer[i] = '\0';
    return i;

}

void find_string();
void find_string()
{
    // Read first line of code
    get_next_line(fp_ORIGINAL);

    char test_string[256] = "WR #: ";
    int test_string_length = strlen(test_string);
    printf("\nTest String Length: %d\n", test_string_length);
    char temp_data_buffer[50];


    char *p_char;
    p_char = strstr(transfer_buffer, test_string);

    // if p_char is not null than the test_string exists

    // String Span
    char n_set[] ="1234567890";
    int wr_string_span = 7;// = strspn(transfer_buffer, n_set);
    printf("\nWR String Span: %d\n", wr_string_span);

    // Copy over the charachters
    strncpy(temp_data_buffer, p_char, test_string_length+wr_string_span);

    printf("\nThis Should Work:\n%s\n",temp_data_buffer);

    printf("\np_char = %c", p_char[0]);
//    printf("\n p_char = %d", p_char[0]);
//    printf("\n temp_data_buffer = %c",temp_data_buffer);
//    printf("\n temp_data_buffer = %d",temp_data_buffer);

    char temp_c = 'a';
    int temp_i = 0;

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

}




#endif // DATA_HANDLER_H_INCLUDED
