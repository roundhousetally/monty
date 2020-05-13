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
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;

	if ((*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = n;
}
