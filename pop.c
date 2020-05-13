#include "monty.h"

/**
 * pop - deletes the top node of a stack
 * @stack: stack top
 * @ln: att unused
 * Return: void
 */

void pop(stack_t **stack, const unsigned int ln __attribute__((unused)))
{
	stack_t *old = *stack;

	if (old == NULL)
	{
		freeall(*stack, (char *)args[0], (FILE *)args[1], *((int *)args[2]));
		dprintf(2, "L%d: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;

	free(old);
}
