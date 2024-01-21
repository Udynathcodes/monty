#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack.
 * @stack: Pointer to the stack.
 * @num_line: Line where the mul function is called.
 */
void pstr(stack_t **stack, unsigned int num_line)
{
	stack_t *var1;

	(void) stack;
	(void) num_line;

	var1 = coments->top;

	while (var1 != NULL)
	{
		if (var1->n <= 0 || var1->n > 127)
			break;
		printf("%c", var1->n);
		var1 = var1->next;
	}

	printf("\n");
}
