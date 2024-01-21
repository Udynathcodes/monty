#include "monty.h"

/**
 * is_num - Checks if a string represents a valid integer number.
 * @udy:  string to check.
 * Return: 1 if string is  valid , 0 otherwise.
 */
int is_num(char *udy)
{
	int u = 0;

	while (udy[u])
	{
		if (u == 0 && udy[u] == '-' && udy[u + 1])
		{
			u++;
			continue;
		}
		if (udy[u] < '0' || udy[u] > '9')
			return (0);
		u++;
	}

	return (1);
}
