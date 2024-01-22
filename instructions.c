#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the stack.
 * @num_line: Line number where the sub function is called.
 */

void sub(stack_t **stack, unsigned int num_line)
{
	stack_t *var1, *var2;

	(void) stack;
	if (coments->stacklenght < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num_line);
		coments_freeall();
		exit(EXIT_FAILURE);
	}

	var1 = coments->top;
	var2 = var1->next;

	var2->n = var2->n - var1->n;
	remove_stack();

	coments->stacklenght -= 1;
}

#include "monty.h"

/**
 * nop - does nothing
 * @stack: Pointer to the stack.
 * @num_line: Line number where the nop function is called.
 */

void nop(stack_t **stack, unsigned int num_line)
{
	(void) stack;
	(void) num_line;
}
