/**
 * are_digits - checks if strings contains only digits
 * @str: string input
 * Return: 1 if it contains only digits else 0
 */

int are_digits(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
