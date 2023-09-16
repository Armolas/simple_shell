#include "main.h"

/**
 * get_path - gets the full path of a file
 * @arg: file to find
 * Return: pointer to full path
 */
char *get_path(char *arg)
{
	char *path = get_env("PATH");
	char *path_token, *fullpath, *fullpathtemp, *pathcopy = str_dup(path);
	struct stat filestat;

	if (!arg)
	{
		free(pathcopy);
		return (NULL);
	}
	if (stat(arg, &filestat) == 0)
	{
		fullpath = strdup(arg);
		free(pathcopy);
		return (fullpath);
	}
	path_token = strtok(pathcopy, ":");
	while (path_token)
	{
		fullpathtemp = concat(path_token, "/");
		fullpath = concat(fullpathtemp, arg);
		if (stat(fullpath, &filestat) == 0)
		{
			free(pathcopy);
			free(fullpathtemp);
			return (fullpath);
		}
		free(fullpathtemp);
		free(fullpath);
		path_token = strtok(NULL, ":");
	}
	free(pathcopy);
	return (NULL);
}
