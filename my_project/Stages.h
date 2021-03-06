#ifndef PROGRAM_MANAGER_H_INCLUDED
#define PROGRAM_MANAGER_H_INCLUDED

// Included Libraries
#include <file_handler.h>
#include <data_handler.h>
#include <User_Interface_Functions.h>

/* Stages */
int  stage_manager(void);
int  stage_1(void);
int  stage_2(void);
void stage_3(void);
void stage_4(void);
int  stage_clean_up(void);

/* Stages */
int  stage_manager(void)
{
    // Request WR Number and Open Existing file
    stage_1();
    stage_2();

    // Stage_3: Transfer Criteria
    stage_3();


    stage_clean_up();
}

/* Stage 4: Transfer Engine
*/
void stage_4(void)
{

}

/* Stage 3: Obtain and Transfer WR Number and Revision Number
*/
void stage_3(void)
{
    // Get WR Number
    get_WR_number(temp_data_buffer);

    // Transfer WR Number
    WRITE_FORMATTED("WR #: ");
    WRITE_FORMATTED(temp_data_buffer);
    WRITE_FORMATTED("\n");

    // Get Revision Number
    Get_Next_Line_ORIGINAL(temp_data_buffer);

    // Transfer Revision Number
    WRITE_FORMATTED(temp_data_buffer);

    skip_n_lines(fp_ORIGINAL, 3);
    Get_Next_Line_ORIGINAL(temp_data_buffer);
    printf("Three Lines Skipped: %s", temp_data_buffer);
    WRITE_FORMATTED(temp_data_buffer);

}

/* Stage Clean up:
    - Closes both file pointers
*/
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
