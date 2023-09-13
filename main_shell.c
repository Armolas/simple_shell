#include "main.h"

/**
 * main - entry point for the shell program
 * Return: 0 on sucess or -1 when it fails
 */
int main()
{

	char **args, *linebuf = NULL, *delim = " \n";
	extern char **environ;
	size_t linesize = 0;
	pid_t child;
	int nb_got, is = 0;

	while (1)
	{
		(isatty(0) == 1) ? printf(":) ") : is++;
		nb_got = getline(&linebuf, &linesize, stdin);
		if (nb_got == -1 || str_cmp(linebuf, "exit\n") == 0)
			break;
		else if (nb_got == 1)
		{
			free(linebuf);
			continue;
		}
		else
		{
			args = get_args(linebuf, delim);
			args[0] = get_path(args[0]);
			if (!args[0])
			{
				/*dprintf(2, ":( command not found\n");*/
				free_args(args);
				continue;
			}
			child = fork();
			if (child == -1)
			{
				perror("unable to create new process");
				free_args(args);
				return(-1);
			}
			else if (child == 0)
			{
				execve(args[0], args, environ);
				perror("execve failed\n");
				free_args(args);
				return (-1);
			}
			else
			{
				wait(NULL);
				free_args(args);
			}
		}
	}
	free(linebuf);
	return (0);
}
