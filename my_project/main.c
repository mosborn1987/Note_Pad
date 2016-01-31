#include <program_manager.h>
#include <data_handler.h>

int main()
{
    // Request WR Number and Open Existing file
    stage_1();
    stage_2();

    // Get Next Line
    Get_Next_Line_ORIGINAL(transfer_buffer);

    // Print String
    printf("First Line: %s",transfer_buffer);


//    find_string();

    // Stage 3 - Obtain and Transfer WR Number and Revision Number
//    stage_3();


    stage_clean_up();


   return(0);
}
