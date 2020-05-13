#include "monty.h"

/**
 * free_stack_t - free's a stack
 * @stack: stack to free
 * Return: void
 */

void free_stack_t(stack_t *stack)
{
	stack_t *current = stack;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
