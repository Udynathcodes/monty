#include "monty.h"

/**
* free_nodestack - free the nodes in a stack list
* @top: first node of a dlistint link
* Return: void
*/
void free_nodestack(stack_t *top)
{
	if (top == NULL)
		return;

	if (top->next != NULL)
	{
		free_nodestack(top->next);
	}

	free(top);
}

/**
 * coments_freeall - Frees all allocated memory for arguments.
 */

void coments_freeall(void)
{
	free_coments();
	stream_close();
	tokens_free();
}

/**
* remove_stack - remove node at the top of the stack.
* Return: void
*/
void remove_stack(void)
{
	stack_t *var;

	var = coments->top;
	coments->top = var->next;
	free(var);
}
