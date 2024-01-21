#include "monty.h"

/**
 * unknown_instruct - Handles unknown instructions errors.
 */

void unknown_instruct(void)
{
	dprintf(2, "L%d: unknown instruction %s\n",
			coments->num_line, coments->token[0]);
	stream_close();
	tokens_free();
	free_coments();
	exit(EXIT_FAILURE);
}

/**
 * utilities - get instructions base on tokens.
 */

void utilities(void)
{
	int u = 0;
	instruction_t instruct[] = {
		{"push", &push}, {"pop", &pop},
		{"pint", &pint}, {"swap", &swap},
		{"nop", &nop}, {"add", &add},
		{"pall", &pall}, {"sub", &sub},
		{"rotl", &rotl}, {"rotr", &rotr},
		{"pstr", &pstr}, {"pchar", &pchar},
		{"mod", &mod},
		{NULL, NULL}
	};

	if (coments->tokens_num == 0)
		return;
	for (; instruct[u].opcode != NULL; u++)
	{
		if (strcmp(instruct[u].opcode, coments->token[0]) == 0)
		{
			coments->instruct->opcode = instruct[u].opcode;
			coments->instruct->f = instruct[u].f;
			return;
		}
	}
	unknown_instruct();
}

/**
 * tokens_free - free allocated memory for all tokens.
 */

void tokens_free(void)
{
	int u;

	if (coments->token == NULL)
		return;

	for (u = 0; coments->token[u] != NULL; u++)
	{
		free(coments->token[u]);
	}
	free(coments->token);
	coments->token = NULL;
}

/**
 * stream_close - shut file stream and assign it to NULL.
 */

void stream_close(void)
{
	if (coments->streams == NULL)
		return;

	fclose(coments->streams);
	coments->streams = NULL;
}

/**
 * loop_instruct - loop through the instructions specified by the coments.
 */

void loop_instruct(void)
{
	stack_t *stack = NULL;

	if (coments->tokens_num == 0)
		return;

	coments->instruct->f(&stack, coments->num_line);
}
