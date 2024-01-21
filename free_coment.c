#include "monty.h"

/**
* free_coments - free memory allocated to coments pointer
*/

void free_coments(void)
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
