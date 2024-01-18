#include "monty.h"

/**
 * pall - returns all the elements in the stack.
 * @stack: Pointer to the stack.
 * @num_line: Line number to the pall function
 */
void pall(stack_t **stack, unsigned int num_line)
{
	stack_t *var;

	if (coments->top == NULL)
		return;

	(void) num_line;
	(void) stack;

	for (var = coments->top; var != NULL; var = var->next)
	{
		printf("%d\n", var->n);
	}
}
