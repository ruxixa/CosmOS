/**
 * screen/screen.h
 * 
 * This file contains the functions used
 * to perform operations on the screen.
 * 
 * Author: ruxixa
*/
#ifndef CLEAR_SCREEN_H
#define CLEAR_SCREEN_H

#include "../utils/colors.h"

/**
 * Prints the welcome message.
 * 
 * @param pos - position of the cursor
 * @param vidptr - pointer to the video memory
*/
void print_banner(unsigned int *pos, char *vidptr) {
    _printf(pos, vidptr, FG_LIGHT_BLUE | BG_BLACK, "Welcome to CosmOS!\n");
    _printf(pos, vidptr, FG_WHITE | BG_BLACK, 
            "Type 'help' to see the available commands.\n\n");
}

/**
 * Cleans the screen by filling it with spaces
 * and setting the background color.
 * 
 * @param vidptr - pointer to the video memory
 * @param bg_color - background color
*/
void clean_screen(char *vidptr, unsigned char bg_color) {
    int j = 0;

    while(j < 80 * 25 * 2) {
        vidptr[j] = ' ';
        vidptr[j+1] = bg_color;
        j = j + 2;
    }

    print_banner(&j, vidptr);
}

/**
 * Moves the cursor to a given position.
 * 
 * @param pos - position to move the cursor to
*/
void new_line(unsigned int *pos) {
    *pos = *pos + 160 - *pos % 160;
}

/**
 * Deletes a character from the screen.
 * 
 * @param pos - position of the character to delete
 * @param vidptr - pointer to the video memory
 * 
 * @return void
*/ 
void delete_char(unsigned int *pos, char *vidptr) {
    *pos = *pos - 2;
    vidptr[*pos] = ' ';
    vidptr[*pos + 1] = BG_BLACK;
}


#endif // CLEAR_SCREEN_H