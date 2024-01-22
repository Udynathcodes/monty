#include "monty.h"

t_args *coments = NULL;

/**
 * main - Driver code.
 * @argc: command-line argument.
 * @argv: argument vector.
 * Return: 0 on success.
 */

int main(int argc, char **argv)
{
	size_t size = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	my_args();
	find_stream(argv[1]);

	while (getline(&coments->lines, &size, coments->streams) != -1)
	{
		coments->num_line += 1;
		string_tok();
		utilities();
		loop_instruct();
		tokens_free();
	}

	stream_close();
	free_coments();

	return (0);
}
