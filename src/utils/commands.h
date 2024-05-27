/**
 * utils/commands.h
 * 
 * This file contains functions to handle
 * commands entered by the user.
 * 
 * Author: ruxixa
*/
#include "colors.h"

#include "../screen/in_out.h"
#include "../screen/screen.h"

/**
 * Handles a command entered by the user.
 * 
 * Currently, the available commands are:
 * - help - show a list of available commands
 * - clear - clear the screen
 * - echo - print a message
 * 
 * More commands will be added in the future.
 * 
 * @param command - the command to handle
 * @param pos - the position of the cursor
 * @param vidptr - pointer to the video memory
 *
 * @return void 
*/
void handle_command(const char* command, unsigned int *pos, char *vidptr) {
    if (_strcmp(command, "help") == 0) {
        _printf(pos, vidptr, FG_LIGHT_BLUE | BG_BLACK, "\nAvailable commands:");
        _printf(pos, vidptr, FG_LIGHT_BLUE | BG_BLACK, "\n- help - show a list of available commands");
        _printf(pos, vidptr, FG_LIGHT_BLUE | BG_BLACK, "\n- clear - clear the screen");
        _printf(pos, vidptr, FG_LIGHT_BLUE | BG_BLACK, "\n- echo - print a message\n");
    } 
    else if (_strcmp(command, "clear") == 0) {
        clean_screen(vidptr, BG_BLACK);
        *pos = 0; 
    } 
    else if (_strcmp(command, "echo") == 0) {
        char message[MAX_BUFFER_SIZE];

        _printf(pos, vidptr, FG_LIGHT_BLUE | BG_BLACK, "\nEnter a message: ");
        _scanf(pos, vidptr, FG_WHITE | BG_BLACK, "%s", message);
        _printf(pos, vidptr, FG_WHITE | BG_BLACK, "\n%s\n", message);
    }
    else {
        _printf(pos, vidptr, FG_LIGHT_RED | BG_BLACK, "\nCommand not found: %s\n", command);
    }
}