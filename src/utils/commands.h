#include "colors.h"

#include "../screen/in_out.h"
#include "../screen/screen.h"

void handle_command(const char* command, unsigned int *pos, char *vidptr) {
    if (_strcmp(command, "help") == 0) {
        _printf(pos, vidptr, FG_LIGHT_BLUE | BG_BLACK, "\nAvailable commands:");
        _printf(pos, vidptr, FG_LIGHT_BLUE | BG_BLACK, "\n- help - show a list of available commands");
        _printf(pos, vidptr, FG_LIGHT_BLUE | BG_BLACK, "\n- clear - clear the screen");
        _printf(pos, vidptr, FG_LIGHT_BLUE | BG_BLACK, "\n- echo - print a message\n");
    } 
    else if (_strcmp(command, "clear") == 0) {
        clean_screen(vidptr, BG_BLACK);
    } 
}