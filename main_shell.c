#include "main.h"

/**
 * main - entry point for the shell program
 * Return: 0 on sucess or -1 when it fails
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{

	char **args, *linebuf = NULL, *delim = " \n", *cmd;
	size_t linesize = 0;
	pid_t child;
	int nb_got, is = 0, exitstatus = 0, status;

	while (1)
	{
		(isatty(0) == 1) ? printf(":) ") : is++;
		nb_got = getline(&linebuf, &linesize, stdin);
		if (nb_got == -1 || str_cmp(linebuf, "exit\n") == 0)
			break;
		else if (nb_got == 1)
		{
			continue;
		}
		else
		{
			args = get_args(linebuf, delim);
			is = count_args(args);
			if (is == 2 && str_cmp(args[0], "exit") == 0 && are_digits(args[1]) == 1 && !args[2])
			{
				exitstatus = string_to_int(args[1]);
				free_args(args, is);
				break;
			}
			cmd = args[0];
			if (!cmd)
			{
				free_args(args, is);
				continue;
			}
			args[0] = get_path(cmd);
			if(!args[0])
			{
				p_error(av[0]);
				p_error(": 1: ");
				p_error(cmd);
				p_error(": not found\n");
				free(cmd);
				free_args(args, is);
				exitstatus = 127;
				continue;
			}
			child = fork();
			if (child == -1)
			{
				perror("unable to create new process");
				free(cmd);
				free_args(args, is);
				return (-1);
			}
			else if (child == 0)
			{
				execve(args[0], args, env);
				perror("execve failed\n");
				return (2);
			}
			else
			{
				wait(&status);
				if (WIFEXITED(status))
					exitstatus = WEXITSTATUS(status);
				free(cmd);
				free_args(args, is);
			}
		}
	}
	free(linebuf);
	return (exitstatus);
}
