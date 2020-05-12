#include "monty.h"

void pop(stack_t **stack, const unsigned int ln __attribute__((unused)))
{
	stack_t *old = *stack;

	if (old == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack", ln);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(old);
}
