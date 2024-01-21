#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: Pointer to the stack.
 * @num_line: Line where the mul function is called.
 */

void rotr(stack_t **stack, unsigned int num_line)
{
	stack_t *var, *final;

	(void) stack;
	(void) num_line;
	if (coments->stacklenght < 2)
		return;

	var = coments->top;
	while (var)
	{
		if (var->next == NULL)
		{
			final = var;
			break;
		}
		var = var->next;
	}

	final->prev->next = NULL;
	final->next = coments->top;
	final->prev = NULL;

	coments->top = final;
}
