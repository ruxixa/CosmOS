/**
 * kernel.c
 * 
 * This file contains the main function
 * of CosmOS kernel.
 * 
 * Author: ruxixa
*/
#include <stdbool.h>

#include "utils/colors.h"
#include "screen/in_out.h"
#include "screen/screen.h"
#include "ports/ports.h"
#include "keyboard/keys.h"
#include "utils/commands.h"

/**
 * Main function of the kernel.
 * 
 * This function will be called by the bootloader
 * and will be responsible for handling commands
 * in an infinite loop.
 * 
 * @return void
*/
void main() {
    unsigned int pos = 0;
    char *vidptr = (char*)0xb8000;

    clean_screen(vidptr, BG_BLACK);
    print_banner(&pos, vidptr);

    // infinite loop to receive commands
    while (true) {
        char command[MAX_BUFFER_SIZE];

        _printf(&pos, vidptr, FG_CYAN | BG_BLACK, "CosmOS@user:~$ ");
        _scanf(&pos, vidptr, FG_WHITE | BG_BLACK, "%s", command);
    
        handle_command(command, &pos, vidptr);
    }

    return;
}
