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

	valid_comment(argc);
	my_args();
	find_stream(argv[1]);

	while (getline(&coments->lines, &size, coments->streams) != -1)
	{
		printf("%s", coments->lines);
	}

	return (0);
}
