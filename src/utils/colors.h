/**
 * utils/colors.h
 * 
 * This file contains color codes 
 * for both text and background
 * 
 * Author: ruxixa
*/
#ifndef COLORS_H
#define COLORS_H

// text color codes
#define FG_BLACK         0x0
#define FG_BLUE          0x1
#define FG_GREEN         0x2
#define FG_CYAN          0x3
#define FG_RED           0x4
#define FG_MAGENTA       0x5
#define FG_BROWN         0x6
#define FG_LIGHT_GREY    0x7
#define FG_DARK_GREY     0x8
#define FG_LIGHT_BLUE    0x9
#define FG_LIGHT_GREEN   0xA
#define FG_LIGHT_CYAN    0xB
#define FG_LIGHT_RED     0xC
#define FG_LIGHT_MAGENTA 0xD
#define FG_YELLOW        0xE
#define FG_WHITE         0xF

// background color codes
#define BG_BLACK         0x00
#define BG_BLUE          0x10
#define BG_GREEN         0x20
#define BG_CYAN          0x30
#define BG_RED           0x40
#define BG_MAGENTA       0x50
#define BG_BROWN         0x60
#define BG_LIGHT_GREY    0x70
#define BG_DARK_GREY     0x80
#define BG_LIGHT_BLUE    0x90
#define BG_LIGHT_GREEN   0xA0
#define BG_LIGHT_CYAN    0xB0
#define BG_LIGHT_RED     0xC0
#define BG_LIGHT_MAGENTA 0xD0
#define BG_YELLOW        0xE0
#define BG_WHITE         0xF0

/**
 * Mix foreground and background color 
 * to create a single color
 * 
 * @param fg foreground color
 * @param bg background color
 * 
 * @return final color
*/
#define MAKE_COLOR(fg, bg) ((bg) | (fg))

#endif  // COLORS_H