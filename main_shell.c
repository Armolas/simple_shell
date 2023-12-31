#include "main.h"

/**
 * main - entry point for the shell program
 * @ac: argument count
 * @av: array of string arguments to main
 * @env: environment
 * Return: 0 on sucess or -1 when it fails
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{

	char **args, *linebuf = NULL, *delim = " \n", *cmd;
	size_t linesize = 0;
	int nb_got, is = 0, exitstatus = 0;

	while (1)
	{
		(isatty(0) == 1) ? printf(":) ") : is++;
		nb_got = getline(&linebuf, &linesize, stdin);
		if (nb_got == -1 || str_cmp(linebuf, "exit\n") == 0)
			break;
		else if (nb_got == 1)
			continue;
		else
		{
			args = get_args(linebuf, delim);
			is = count_args(args);
			if (is == 2 && str_cmp(args[0], "exit") == 0)
			{
				exitstatus = exit_arg(args, av[0], is);
				break;
			}
			cmd = args[0];
			if (inbuilt(args, cmd, av[0], is, &exitstatus) == 0)
				continue;
			exitstatus = fork_child(args, env, cmd, is);
			if (exitstatus < 0)
				break;
		}
	}
	free(linebuf);
	return (exitstatus);
}
