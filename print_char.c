#include "monty.h"

/**
 * pchar - prints the char at the top of the stack.
 * @stack: Pointer to the stack.
 * @num_line: Line number where the mul function is called.
 */
void pchar(stack_t **stack, unsigned int num_line)
{
	stack_t *var1;

	(void) stack;
	if (coments->top == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", num_line);
		coments_freeall();
		exit(EXIT_FAILURE);
	}

	var1 = coments->top;

	if (var1->n < 0 || var1->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", num_line);
		coments_freeall();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", var1->n);
}
