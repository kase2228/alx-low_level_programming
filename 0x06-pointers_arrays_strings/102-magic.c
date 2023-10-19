#include <stdio.h>
/**
 * main - Program's Starting Point
 *
 * Description:
 * This program showcases how to manipulate memory using pointers. It starts
 * by setting up an integer array 'a' and a pointer 'p.' The objective is to
 * alter a memory value by utilizing the 'p' pointer, without directly
 * interacting with the 'a' array.
 *
 * Return: 0 (Success)
 */

int main(void)
{
	int n;
	int a[5];
	int *p;

	a[2] = 1024;
	p = &n;
	/**
	* write your line of code here...
	* Remember:
	* - you are not allowed to use a
	* - you are not allowed to modify p
	* - only one statement
	* - you are not allowed to code anything else than this line of code
	*/
	p[5] = 98;
	/* ...so that this prints 98\n */
	printf("a[2] = %d\n", a[2]);
	return (0);
}
