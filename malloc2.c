#include "monty.h"

/**
 * my_args - pointer to s_args structs.
 */

void my_args(void)
{
	coments = malloc(sizeof(t_args));
	if (coments == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(coments);
		exit(EXIT_FAILURE);
	}
	coments->instruct = malloc(sizeof(instruction_t));
	if (coments->instruct == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(coments);
		exit(EXIT_FAILURE);
	}
	coments->streams = NULL;
	coments->lines = NULL;
	coments->tokens_num = 0;
	coments->num_line = 0;
}

/**
 * find_stream - fine streams for specified file reading.
 * @file_name: file name to open stream.
 */

void find_stream(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		free(coments);
		exit(EXIT_FAILURE);
	}
	coments->streams = fdopen(fd, "r");
	if (coments->streams == NULL)
	{
		close(fd);
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		free(coments);
		exit(EXIT_FAILURE);
	}
}
