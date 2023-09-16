#include "main.h"

/**
 * p_error - prints to standard error
 * @str: string to print
 */
void p_error(char *str)
{
	int len = str_len(str);

	write(2, str, len);
}
