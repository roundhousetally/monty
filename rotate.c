#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: stack
 * @ln: line number
 */
void rotl(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	stack_t *tmp = *stack, *it;

	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;

	*stack = tmp->next;
	(*stack)->prev = NULL;
	it = *stack;

	while (it->next != NULL)
		it = it->next;

	it->next = tmp;
	tmp->prev = it;
	tmp->next = NULL;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: stack
 * @ln: line number
 */
void rotr(stack_t **stack, unsigned int ln __attribute__((unused)))
{
	stack_t *tmp = *stack, *it = *stack;

	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;

	while (tmp->next != NULL)
		tmp = tmp->next;

	*stack = tmp;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	it->prev = tmp;
	tmp->next = it;
}
