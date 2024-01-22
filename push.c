#include "monty.h"

/**
 * push - Pushes an element into the stack.
 * @stack: Pointer to the stack.
 * @num_line: num line where the push function is called.
 */
void push(stack_t **stack, unsigned int num_line)
{
	if (coments->tokens_num <= 1 || !(is_num(coments->token[1])))
	{
		free_coments();
		fprintf(stderr, "L%d: usage: push integer\n", num_line);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		failed_malloc();
	(*stack)->next = (*stack)->prev = NULL;
	(*stack)->n = (int) atoi(coments->token[1]);
	if (coments->top == NULL)
		coments->top = *stack;
	else
	{
		if (coments->stack)
		{
			(*stack)->next = coments->top;
			coments->top->prev = *stack;
			coments->top = *stack;
		}
		else
		{
			stack_t *var = coments->top;

			while (var->next)
				var = var->next;
			var->next = *stack;
			(*stack)->prev = var;
		}
	}
	coments->stacklenght += 1;
}
