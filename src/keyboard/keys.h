/**
 * keyboard/keys.h
 * 
 * This file contains definitions for keyboard keys.
 * 
 * Author: ruxixa
*/
#ifndef KEYS_H
#define KEYS_H

// special keys
#define KEYBOARD_ENTER 28
#define KEYBOARD_ESC 1
#define KEYBOARD_BACKSPACE 14
#define KEYBOARD_TAB 15

/**
 * Converts a key code to an ASCII character.
 * 
 * @param key The key code to convert.
 * @return The ASCII character corresponding to the key code.
*/
int key_to_ascii(int key) {
    int keyboardLayout[] = {
        -1, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 8,  // 0-14
        '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', // 15-28
        -1, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',        // 29-41
        -1, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'              // 42-53
    };

    // check if the key is within the range of the keyboard layout
    if (key >= 0 && key < sizeof(keyboardLayout) / sizeof(keyboardLayout[0])) {
        return keyboardLayout[key];
    } 
    else {
        return -1;
    }
}

#endif // KEYS_H