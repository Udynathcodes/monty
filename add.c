#include "monty.h"

/**
 * add - sum top two elements of the stack.
 * @stack: Pointer to the stack.
 * @num_line: Line  where the add function is called.
 */
void add(stack_t **stack, unsigned int num_line)
{
	stack_t *var1, *var2;

	(void) stack;
	if (coments->stacklenght < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
				num_line);
		coments_freeall();
		exit(EXIT_FAILURE);
	}

	var1 = coments->top;
	var2 = var1->next;

	var2->n = var1->n + var2->n;
	remove_stack();

	coments->stacklenght -= 1;
}
