#include "main.h"
/**
 * penv - prints environment
 */
void penv(char **args, int is)
{
	extern char **environ;
	int i = 0;

	if (!environ)
		return;
	while(environ[i])
	{
		_puts(environ[i]);
		_puts("\n");
		i++;
	}
	free_args(args, is);
}
