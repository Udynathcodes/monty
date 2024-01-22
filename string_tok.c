#include "monty.h"
/**
 * string_tok - tokenize file.
 */
void string_tok(void)
{
	char *tok = NULL, *copy_line = NULL, *delim = " \n";
	int u = 0;

	copy_line = malloc(sizeof(char) * (strlen(coments->lines + 1)));
	strcpy(copy_line, coments->lines);
	coments->tokens_num = 0;
	tok = strtok(copy_line, delim);
	while (tok)
	{
		coments->tokens_num += 1;
		tok = strtok(NULL, delim);
	}

	coments->token = malloc(sizeof(char *) * (coments->tokens_num + 1));
	strcpy(copy_line, coments->lines);
	tok = strtok(copy_line, delim);
	while (tok)
	{
		coments->token[u] = malloc(sizeof(char) * (strlen(tok) + 1));
		if (coments->token[u] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(coments);
			exit(EXIT_FAILURE);
		}
		strcpy(coments->token[u], tok);
		tok = strtok(NULL, delim);
		u++;
	}
	coments->token[u] = NULL;
	free(copy_line);
}
