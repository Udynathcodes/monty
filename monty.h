#ifndef _MONTY_H
#define _MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct s_args - variable holder.
 * @streams: file connector.
 * @lines: strings that contains the text read from streams.
 *
 * Desscription: functions variable holders for memory allocation
 */
typedef struct s_args
{
	FILE *streams;
	char *lines;
	char **token;
	int tokens_num;
	unsigned int num_line;
	instruction_t *instruct;
}t_args;

extern t_args *coments;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
	
	/* functions prototypes */
void valid_comment(int argc);
void find_stream(char *file_name);
void my_args();
#endif /* _MONTY_H_ */
