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
			if (str_cmp(args[0], "env") == 0)
			{
				penv(args, is);
				continue;
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
				exitstatus = null_arg(args, cmd, av[0], is);
				continue;
			}
			child = fork();
			if (child == -1)
				return (child_fail(args, cmd, is));
			else if (child == 0)
			{
				execve(args[0], args, env);
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
