#include "main.h"
extern char **environ;
/**
 * @args: array of string inputs to the shell
 * @is: number of string input
 * penv - prints environment
 */
void penv(char **args, int is)
{
	int i = 0;

	if (!environ)
		return;
	while (environ[i])
	{
		_puts(environ[i]);
		_puts("\n");
		i++;
	}
	free_args(args, is);
}
