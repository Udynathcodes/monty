#include "monty.h"

/**
 *failed_malloc - Handles  malloc failures to allocate memory.
 */

void failed_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
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
