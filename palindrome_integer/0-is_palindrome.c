#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"


/**
 * main - Entry point
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

#include <stdio.h>
#include <stdbool.h>

int is_palindrome(unsigned long n) {
    char str[20];
    int m, i;
    
    m = sprintf(str, "%lu", n);
    
    for (i = 0; i < m / 2; i++) {
        if (str[i] != str[m - i - 1]) {
            return false;
        }
    }
    
    return true;
}

