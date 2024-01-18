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
 * @num_line: for tracking current line number
 * @token: used to store tokens from line
 * @instruct: returns valid instruction from a line
 * @tokens_num: number of tokens created
 * @top: top of the stack (doubly linked lists of struct stack_s)
 * @stacklenght: tracks the num of nodes in the stack
 * @stack: determine whether to use stack/queue data structure
 * @lines: strings that contains the text read from streams.
 *
 * Desscription: functions variable holders for memory allocation
 */
typedef struct s_args
{
	FILE *streams;
	stack_t *top;
	char **token, *lines;
	int tokens_num, stack, stacklenght;
	unsigned int num_line;
	instruction_t *instruct;
} t_args;

extern t_args *coments;

	/* utilities */
void push(stack_t **stack, unsigned int num_line);
void pop(stack_t **stack, unsigned int num_line);
void pint(stack_t **stack, unsigned int num_line);
void pall(stack_t **stack, unsigned int num_line);
void swap(stack_t **stack, unsigned int num_line);
void add(stack_t **stack, unsigned int num_line);
void nop(stack_t **stack, unsigned int num_line);
void sub(stack_t **stack, unsigned int num_line);
void _div(stack_t **stack, unsigned int num_line);
void mul(stack_t **stack, unsigned int num_line);
void mod(stack_t **stack, unsigned int num_line);
void pchar(stack_t **stack, unsigned int num_line);
void pstr(stack_t **stack, unsigned int num_line);
void rotl(stack_t **stack, unsigned int num_line);
void rotr(stack_t **stack, unsigned int num_line);
void stack(stack_t **stack, unsigned int num_line);
void queue(stack_t **stack, unsigned int num_line);

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
void my_args(void);
void utilities(void);
void invalid_instruct(void);
void loop_instruct(void);
void free_coments(void);
void tokens_free(void);
void stream_close(void);
void string_tok(void);
void failed_malloc(void);
#endif /* _MONTY_H_ */
