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

void clean_screen(char *vidptr, unsigned char bg_color) {
    int j = 0;

    while(j < 80 * 25 * 2) {
        vidptr[j] = ' ';
        vidptr[j+1] = bg_color;
        j = j + 2;
    }
}

void new_line(unsigned int *pos) {
    *pos = *pos + 160 - *pos % 160;
}

void delete_char(unsigned int *pos, char *vidptr) {
    *pos = *pos - 2;
    vidptr[*pos] = ' ';
    vidptr[*pos + 1] = BG_BLACK;
}

#endif // CLEAR_SCREEN_H