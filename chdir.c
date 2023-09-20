#include "main.h"
/**
 * _chdir - implements cd builtin
 * @dir_name: name of destination directory
 * @av: program command
 * Return: 0 or -1
 */
int _chdir(char *dir_name, char *av)
{
	char *old = get_env("OLDPWD");
	char *current = malloc(sizeof(char) * 1024), *home = get_env("HOME");
	size_t cur_size = 1024;
	int ret;

	if (!dir_name)
	{
		chdir(home);
		getcwd(current, cur_size);
		setenv("PWD", current, 1);
		free(current);
		return (0);
	}
	if (str_cmp(dir_name, "-") == 0)
	{
		chdir(old);
		getcwd(current, cur_size);
		_puts(current);
		_puts("\n");
		setenv("PWD", current, 1);
		free(current);
		return (0);
	}
	ret = chdir(dir_name);
	if (ret < 0)
	{
		p_error(av);
		p_error(": 1: cd: can't cd to ");
		p_error(dir_name);
		p_error("\n");
		free(current);
		return (-1);
	}
	getcwd(current, cur_size);
	setenv("PWD", current, 1);
	free(current);
	return (0);
}
