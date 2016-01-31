#ifndef USER_INTERFACE_FUNCTIONS_H_INCLUDED
#define USER_INTERFACE_FUNCTIONS_H_INCLUDED

#include <file_handler.h>

// Prototypes

// Request WR Number from user
void UI_Request_WR_Number(void);
void UI_Re_Request_WR_Number(void);

// Prototype declaration

// Request WR Number from user
void UI_Request_WR_Number(void)
{
    // Clean array
    WR_Number[0] = '\0';

    // Prompt User For number
    printf("Please Enter WR Number: ");

    // Scan In number
    scanf("%s", WR_Number);

}

void UI_Re_Request_WR_Number(void)
{
    // Print Prompt to try again
    printf("\n\nSorry, %s is not a valid file.\n\n", WR_Number);

    // Re_request the User to enter WR Number.

    UI_Request_WR_Number();

}

#endif // USER_INTERFACE_FUNCTIONS_H_INCLUDED
