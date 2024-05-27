/**
 * helpers/values.h
 * 
 * This file contains helper functions for
 * converting values
 * 
 * Author: ruxixa
*/

#ifndef VALUES_H
#define VALUES_H

/**
 * Converts an integer to a string
 * 
 * @param num    - the number to be converted
 * @param str    - the string to store the result
 * @param base   - the base of the number
 * 
 * @return char* - the converted string
*/
char* _itoa(int num, char* str, int base) {
    int i = 0;
    int is_negative = 0;

    // if the number is negative, 
    // make it positive and set the flag
    if (num < 0 && base == 10) {
        is_negative = 1;
        num = -num;
    }

    // process individual digits
    do {
        int digit = num % base;
        str[i++] = (digit > 9) ? (digit - 10) + 'a' : digit + '0';
        num /= base;
    } while (num != 0);

    if (is_negative) {
        str[i++] = '-';
    }

    // reverse the string
    int j = 0;
    for (j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }

    // null terminate the string
    str[i] = '\0';
    
    return str;
}

/**
 * Converts a string to an integer
 * 
 * @param str    - the string to be converted
 * 
 * @return int   - the converted integer
*/
int _atoi(char* str) {
    int res = 0;
    int sign = 1;
    int i = 0;

    // handle negative numbers
    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    // process individual digits
    for (; str[i] != '\0'; ++i) {
        res = res * 10 + str[i] - '0';
    }

    return sign * res;
}

/**
 * Copies a string from src to dest
 * 
 * @param dest   - the destination string
 * @param src    - the source string
 * 
 * @return char* - the destination string
*/
char* _strcpy(char* dest, const char* src) {
    char* ptr = dest;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
    return ptr;
}

/**
 * Compares two strings.
 * 
 * @param str1 - pointer to the first string
 * @param str2 - pointer to the second string
 * 
 * @return integer less than, equal to, or greater than zero if the first string
 *         is found, respectively, to be less than, to match, or be greater than
 *         the second string.
*/
int _strcmp(const char* str1, const char* str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}


#endif // VALUES_H