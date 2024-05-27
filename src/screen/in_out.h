/**
 * screen/in_out.h
 * 
 * This file contains functions for input/output 
 * operations on the screen.
 * 
 * Since we are working on a kernel, we dont 
 * have access to the standard library functions, 
 * such as printf, scanf, etc. so we need to 
 * implement them ourselves.
 * 
 * Author: ruxixa
*/
#ifndef IN_OUT_H
#define IN_OUT_H

#define MAX_BUFFER_SIZE 255

#include <stdarg.h>

#include "../helpers/values.h"
#include "../keyboard/keys.h"
#include "../ports/ports.h"

/**
 * Writes a character to the video memory.
 * 
 * @param c      - character to be written
 * @param pos    - pointer to the current position in the video memory
 * @param vidptr - pointer to the video memory
 * @param color  - color of the text
 * 
 * @return void
*/
void _putchar(char c, unsigned int *pos, char *vidptr, unsigned char color) {
    vidptr[*pos] = c;
    vidptr[*pos + 1] = color;

    // move the position by 2 bytes 
    // (1 byte for the character, 1 byte for the color)
    (*pos) += 2;
}

/**
 * Reads a string from the keyboard.
 * 
 * @param input  - pointer to the input buffer
 * @param pos    - pointer to the current position in the video memory
 * @param vidptr - pointer to the video memory
 * @param color  - color of the text
 * 
 * @return void
*/
void _gets(char *input, unsigned int *pos, char *vidptr, unsigned char color) {
    char prev_key = 0;
    int i = 0;
    while (1) {
        char c = inb(KEYBOARD_PORT);
        
        if (c < 0) continue;                // negative value means no key was pressed
        else if (c == 28) break;            // enter key; exit the loop
        else if (c == prev_key) continue;   // ignore key repeats
        else if (c == 14) {                 // backspace key; handle input deletion
            if (i > 0) {
                delete_char(pos, vidptr);
                i--;
            }
            continue;
        }
        
        prev_key = c;
        char key = key_to_ascii(c);
        
        _putchar(key, pos, vidptr, color);
        _printf(pos, vidptr, color, "-> %c", key);
        
        input[i] = key;
        i++;
        
        // limit the input to 100 characters 
        // to prevent buffer overflow 
        if (i >= 99) break;                 
    }
    input[i] = '\0';
}

/**
 * Reads formatted input from the keyboard and stores 
 * the data into the given buffer.
 * 
 * Supported formats:
 * - %c - character
 * - %s - string
 * - %d - integer
 * 
 * @param input  - pointer to the input buffer
 * @param pos    - pointer to the current position in the video memory
 * @param vidptr - pointer to the video memory
 * @param color  - color of the text
 * @param format - format string
 * @param ...    - arguments to be formatted
 * 
 * @return void
*/
void _scanf(unsigned int *pos, char *vidptr, unsigned char color, const char *format, ...) {
    char input[MAX_BUFFER_SIZE];

    // Call _gets() to read input string
    _gets(input, pos, vidptr, color);

    // If no format string is provided, return
    if (format == (void*)0) return;

    va_list args;
    va_start(args, format);

    // Process format string
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    char *arg = va_arg(args, char *);

                    // Read the first character from the input buffer
                    *arg = input[0]; 
                    break;
                }
                case 's': {
                    char *arg = va_arg(args, char *);

                    // Copy the entire input buffer
                    _strcpy(arg, input); 
                    break;
                }
                case 'd': {
                    int *arg = va_arg(args, int *);

                    // Convert the input buffer to an integer
                    *arg = _atoi(input); 
                    break;
                }
            }
        }

        // Move to the next format specifier
        format++;
    }

    va_end(args);
}

/**
 * Writes out the text in a given format to the screen. 
 * 
 * Supported formats:
 * - %c - character
 * - %s - string
 * - %d - integer
 * 
 * @param pos    - pointer to the current position in the video memory
 * @param vidptr - pointer to the video memory
 * @param color  - color of the text
 * @param format - format string
 * @param ...    - arguments to be formatted
 * 
 * @return void
*/
void _printf(unsigned int *pos, char *vidptr, unsigned char color, const char *format, ...) {
    va_list args;
    va_start(args, format);

    // '/0' is the null terminator, 
    // telling us that the string has ended
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    _putchar(va_arg(args, int), pos, vidptr, color);
                    break;
                }
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0') {
                        _putchar(*str++, pos, vidptr, color);
                    }
                    break;
                }
                case 'd': {
                    // convert the integer to a string
                    const char* str = _itoa(va_arg(args, int), (char*)0, 10);
                    while (*str != '\0') {
                        _putchar(*str++, pos, vidptr, color);
                    }
                    break;
                }
                default:
                    _putchar(*format, pos, vidptr, color);
            }
        } 
        else {
            if (*format == '\n') {
                new_line(pos);
            } 
            else {
                _putchar(*format, pos, vidptr, color);
            }
        }

        format++;
    }

    va_end(args);
}

#endif // IN_OUT_H