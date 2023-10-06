#include <stdio.h>

/**
 * main - Prints all single digit numbers of base 10 starting from 0,
 *        using only the putchar function and without char variables.
 *
 * Return: Always 0.
 */
int main(void)
{
int num = 0;

do {
putchar(num + '0');
num++;
} while (num < 10);

putchar('\n');

return (0);
}
