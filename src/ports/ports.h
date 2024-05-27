/**
 * utils/colors.h
 * 
 * This file contains macros and functions
 * for port operations.
 * 
 * Author: ruxixa
*/
#ifndef PORTS_H
#define PORTS_H

#include <stdint.h>

#define KEYBOARD_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

/**
 * Reads a byte from a given port.
 * 
 * We are currently using this function to read
 * from the keyboard port.
 * 
 * This is a very primitive way of doing that
 * and I should write own keyboard driver, what
 * I will probably do in the future.
 * 
 * @param port - port to read from
 * @return char
*/
char inb(uint16_t port) {
    char value;
    asm volatile ("inb %1, %0" : "=a" (value) : "dN" (port));

    return value;
}

#endif  // PORTS_H