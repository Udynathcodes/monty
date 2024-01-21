#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: Pointer to the stack.
 * @num_line: Line where the mul function is called.
 */
void rotl(stack_t **stack, unsigned int num_line)
{
	stack_t *var1, *var2;

	(void) stack;
	(void) num_line;
	if (coments->stacklenght < 2)
		return;

	var1 = coments->top;
	var2 = var1->next;
	coments->top = var2;
	while (var2)
	{
		if (var2->next == NULL)
		{
			var2->next = var1;
			var1->next = NULL;
			var1->prev = var2;
			break;
		}

		var2 = var2->next;
	}
}
