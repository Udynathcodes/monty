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
}

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
 * free_top - Frees  memory allocation for the top and
 * sets it to NULL.
 */

void free_top(void)
{
	if (coments->top)
		free_nodestack(coments->top);

	coments->top = NULL;
}
