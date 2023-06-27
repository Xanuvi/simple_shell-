#include <stdio.h>

/**
 * main - Prints letters from 1 to 9
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char let[9] = "123456789";
	int i;

	for (i = 0; i < 9; i++)
	{
		putchar(let[i]);
	}
	putchar('\n');
	return (0);
}
