#include "main.h"

/**
 * _puts - prints to standard output
 * @str: string to print
 */
void _puts(char *str)
{
	int len = str_len(str);

	write(1, str, len);
}
