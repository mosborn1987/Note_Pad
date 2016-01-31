#ifndef PROGRAM_MANAGER_H_INCLUDED
#define PROGRAM_MANAGER_H_INCLUDED

// Included Libraries
#include <file_handler.h>
#include <data_handler.h>
#include <User_Interface_Functions.h>

/* Stage 3: Obtain and Transfer WR Number and Revision Number
*/
void stage_3(void);

void stage_3(void)
{
    // Get WR Number
    find_string(transfer_buffer);

    // Transfer WR Number

    // Get Revision Number

    // Transfer Revision Number


}


/* Stage Clean up:
    - Closes both file pointers
*/
int stage_clean_up(void);

int stage_clean_up(void)
{
    // Close Original
    CLOSE_ORIGINAL();

    // Close Formatted
    CLOSE_FORMATTED();

    // Return
    return 0;

}

/* Stage 2:
    - Create a new Formatted file
    - Place that in the 'Formatted' folder
*/
int stage_2(void);

int stage_2(void)
{
    // Create a new folder using the WR Number Array
    // Obtained in stage_1.
    CREAT_FORMATTED();

    return 0;
}


/* Stage 1:
    - Request WR From User
    - Verify that the WR Number file exists
        - If so move ahead to Stage 2
        - Else re-request WR Number from user.
*/
int stage_1(void);
// Stage 1
int stage_1(void)
{
    // Request WR From User
    UI_Request_WR_Number();

    // Stitch File Directories
    stitch_file_directories();

    int Open_Status = OPEN_ORIGINAL();

    // Verify that the file pointer is not Null
    while(Open_Status)
    {
        // Re-Request WR Value
        UI_Re_Request_WR_Number();

        // Attempt to Open File Location
        Open_Status = OPEN_ORIGINAL();

    }

    return 0;

}


#endif // PROGRAM_MANAGER_H_INCLUDED
