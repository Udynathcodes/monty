#include "monty.h"

/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @stack: Pointer to the stack.
 * @num_line: Line where the mul function is called.
 */
void mod(stack_t **stack, unsigned int num_line)
{
	stack_t *var1, *var2;

	(void) stack;
	if (coments->stacklenght < 2)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", num_line);
		coments_freeall();
		exit(EXIT_FAILURE);
	}

	var1 = coments->top;
	var2 = var1->next;

	if (var1->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", num_line);
		coments_freeall();
		exit(EXIT_FAILURE);
	}

	var2->n = var2->n % var1->n;
	remove_stack();

	coments->stacklenght -= 1;
}
