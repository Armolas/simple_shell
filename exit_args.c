#include "main.h"

/**
 * exit_arg - implement argument with exit
 * @args: exit arguments
 * @av: progran argument
 * @is: number of args
 * Return: exit status
 */
int exit_arg(char **args, char *av, int is)
{
	int ex = 0;

	if (are_digits(args[1]) == 0)
	{
		ex = string_to_int(args[1]);
		free_args(args, is);
		return (ex);
	}
	ex = 2;
	p_error(av);
	p_error(": 1: exit: Illegal number: ");
	p_error(args[1]);
	p_error("\n");
	free_args(args, is);
	return (ex);
}
