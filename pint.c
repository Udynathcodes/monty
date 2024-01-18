#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Pointer to the stack.
 * @num_line: Line where the pint function is called.
 */

void pint(stack_t **stack, unsigned int num_line)
{
	(void) stack;
	if (coments->top == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", num_line);
		coments_freeall();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", coments->top->n);
}

/**
 * pop - deletes the top element from the stack.
 * @stack: Pointer to the stack.
 * @num_line: Line where the pop function is called.
 */
void pop(stack_t **stack, unsigned int num_line)
{
	(void) stack;
	if (coments->top == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", num_line);
		coments_freeall();
		exit(EXIT_FAILURE);
	}

	remove_stack();
	coments->stacklenght -= 1;
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @num_line: Line  where  swap function is called.
 */
void swap(stack_t **stack, unsigned int num_line)
{
	stack_t *var1, *var2;

	(void) stack;
	if (coments->stacklenght < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", num_line);
		coments_freeall();
		exit(EXIT_FAILURE);
	}

	var1 = coments->top;
	var2 = var1->next;
	var1->next = var2->next;
	if (var1->next)
		var1->next->prev = var1;
	var2->next = var1;
	var1->prev = var2;
	var2->prev = NULL;
	coments->top = var2;
}

