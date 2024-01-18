#include "monty.h"

/**
 * valid_coment - returns the number of command-line argument.
 * @argc: the command-line argument.
 */

void valid_coment(int argc)
{
	if (argc != 2)
		return;

	dprintf(2, "USAGE:monty file\n");
	exit(EXIT_FAILURE);

/**
 *failed_malloc - Handles  malloc failures to allocate memory.
 */

void failed_malloc(void)
{
	dprintf(2, "Error: malloc failed\n");
	free_coments();
	exit(EXIT_FAILURE);
}

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

/**
 * free_top - Frees  memory allocation for the top and
 * sets it to NULL.
 */

void free_top(void)
{
	if (coments->top)
		free_nodestack(coments->top);

	coments->top = NULL;
}

/**
* free_coments - free memory allocated to coments pointer
*/

void free_coments()
{
	if (coments == NULL)
		return;

	if (coments->instruct)
	{
		free(coments->instruct);
		coments->instruct = NULL;
	}

	free_top();

	if (coments->lines)
	{
		free(coments->lines);
		coments->lines = NULL;
	}

	free(coments);
}

