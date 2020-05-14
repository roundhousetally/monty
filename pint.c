#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: stack top
 * @ln: line number
 * Return: void
 */

void pint(stack_t **stack, unsigned int ln)
{
	if (*stack == NULL)
	{
		freeall(*stack, (char *)args[0], (FILE *)args[1], *((int *)args[2]));
		dprintf(2, "L%d: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pchar - prints the char value at the top of the stack
 * @stack: stack top
 * @ln: line number
 * Return: void
 */

void pchar(stack_t **stack, unsigned int ln)
{
	if (*stack == NULL)
	{
		freeall(*stack, (char *)args[0], (FILE *)args[1], *((int *)args[2]));
		dprintf(2, "L%d: can't pchar, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		freeall(*stack, (char *)args[0], (FILE *)args[1], *((int *)args[2]));
		dprintf(2, "L%d: can't pchar, value out of range\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: stack top
 * @ln: line number
 * Return: void
 */

void pstr(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	stack_t *p = *stack;

	while (p != NULL && p->n != '\0' && p->n <= 127 && p->n >= 0)
	{
		printf("%c", p->n);
		p = p->next;
	}
	printf("\n");
}
