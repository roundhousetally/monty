#ifndef MONTY_H
#define MONTY_H

/** Libraries */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/** Our one global var */
extern void *args[5];

/** Structs */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/** Funcs */

stack_t *addnodeint(stack_t **head, int n);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)));
void print_stack_t(stack_t *stack);
void free_stack_t(stack_t *stack);
void pint(stack_t **stack, unsigned int ln);
void pop(stack_t **stack, unsigned int ln);
void nop(stack_t **stack, unsigned int ln);
void swap(stack_t **stack, unsigned int line_number);
void freeall(stack_t *stack, char *line, FILE *file, int fd);
void error(char *str, unsigned int ln, char c);
void add(stack_t **stack, unsigned int ln);
void sub(stack_t **stack, unsigned int ln);
void divy(stack_t **stack, unsigned int ln);
void mul(stack_t **stack, unsigned int ln);
void mod(stack_t **stack, unsigned int ln);
int iscomment(char *line);
#endif
