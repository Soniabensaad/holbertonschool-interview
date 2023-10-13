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
In this corrected code, we removed the check for n < 2 because, as mentioned earlier, all single-digit numbers are palindromes, including 0. Now, the code should correctly check for palindromes and return true when applicable.





