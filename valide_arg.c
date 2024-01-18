#include "monty.h"

/**
 * valid_coment - returns the number of command-line argument.
 * @argc: the command-line argument.
 */

void valid_comment(int argc)
{
	if (argc != 2)
		return;

	dprintf(2, "USAGE:monty file\n");
	exit(EXIT_FAILURE);
}
