#include "main.h"

/**
 * fork_child - creates child process
 * @args: arguments
 * @env: environment
 * @cmd: command
 * @is: number of arguments
 * Return: exit status
 */
int fork_child(char **args, char **env, char *cmd, int is)
{
	int exitstatus = 0, status;
	pid_t child;

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
		free_args(args,is);
	}
	return (exitstatus);
}
