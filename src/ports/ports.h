#ifndef PORTS_H
#define PORTS_H

#include <stdint.h>

#define KEYBOARD_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

/**
 * Reads a byte from a given port.
 * 
 * @param port - port to read from
 * 
 * @return char
*/
char inb(uint16_t port) {
    char value;
    asm volatile ("inb %1, %0" : "=a" (value) : "dN" (port));

    return value;
}

#endif  // PORTS_H