#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: stack top
 * @ln: att unused
 * Return: void
 */

void pint(stack_t **stack, const unsigned int ln __attribute__((unused)))
{
	printf("%d\n", (*stack)->n);
}
