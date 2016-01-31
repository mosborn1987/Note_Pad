#ifndef USER_INTERFACE_FUNCTIONS_H_INCLUDED
#define USER_INTERFACE_FUNCTIONS_H_INCLUDED

#include <file_handler.h>

// Prototypes

// Request WR Number from user
void UI_Request_WR_Number(void);
void UI_Re_Request_WR_Number(void);

// Terminal
void clear_terminal(void);

// Prototype declaration

// Terminal
void clear_terminal(void)
{
    system("cls");

}

// Request WR Number from user
void UI_Request_WR_Number(void)
// TODO (Mario Osborn#1#): UI_Re_Request_WR_Number Not working.
{
    // Clean array
    WR_Number[0] = '\0';

    // Prompt User For number
    printf("Please Enter WR Number: ");

    // Scan In number
    scanf("%s", WR_Number);

    // Clear Terminal Window
    clear_terminal();

}

void UI_Re_Request_WR_Number(void)
{
    clear_terminal();
    // Print Prompt to try again
    printf("Sorry, %s is not a valid file.\n", WR_Number);

    // Re_request the User to enter WR Number.

    UI_Request_WR_Number();

}

#endif // USER_INTERFACE_FUNCTIONS_H_INCLUDED
