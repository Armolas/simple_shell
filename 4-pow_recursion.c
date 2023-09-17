/**
 * _pow_recursion - raise the power of x to y
 * @x: x input
 * @y: y input
 * Return: x to the power y
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, (y - 1)));
}
