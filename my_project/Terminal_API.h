#ifndef TERMINAL_API_H_INCLUDED
#define TERMINAL_API_H_INCLUDED

// Terminal
void clear_terminal(void);
void pause_terminal(void);

// Prototype declaration

// Terminal
void clear_terminal(void)
{
    system("cls");

}

void pause_terminal(void)
{
    system("pause");
}

#endif // TERMINAL_API_H_INCLUDED
