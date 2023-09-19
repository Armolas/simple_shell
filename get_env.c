#include "main.h"
/**
 * get_env - gets an environment variable
 * @var: variable name
 * Return: variable value
 */
char *get_env(char *var)
{
	int i = 0, j;

	if (!var)
		return (NULL);
	while (environ[i])
	{
		j = 0;
		while (environ[i][j] != '=' && var[j])
		{
			if (environ[i][j] == var[j])
			{
				j++;
			}
			else
				break;
		}
		if (environ[i][j] == '=')
		{
			j++;
			return (&environ[i][j++]);
		}
		i++;
	}
	return (NULL);
}
