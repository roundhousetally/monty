#include "monty.h"

/**
 * swap - swaps the first two elements of a stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int n;

	if ((*stack) == NULL)
	{
		freeall(*stack, (char *)args[0], (FILE *)args[1], *((int *)args[2]));
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;

	if ((*stack)->next == NULL)
	{
		freeall(*stack, (char *)args[0], (FILE *)args[1], *((int *)args[2]));
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = n;
}
