#include "monty.h"

/**
 * add - adds the top two items on the stack
 * @stack: stack
 * @ln: line number
 */
void add(stack_t **stack, unsigned int ln)
{
	int tmp;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	pop(stack, ln);
	(*stack)->n += tmp;
}

/**
 * sub - subtracts the top two items on the stack
 * @stack: stack
 * @ln: line number
 */
void sub(stack_t **stack, unsigned int ln)
{
	int tmp;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	pop(stack, ln);
	(*stack)->n -= tmp;
}

/**
 * divy - divides the top two items on the stack
 * @stack: stack
 * @ln: line number
 */
void divy(stack_t **stack, unsigned int ln)
{
	int tmp;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	pop(stack, ln);
	(*stack)->n /= tmp;
}

/**
 * mul - multiplies the top two items on the stack
 * @stack: stack
 * @ln: line number
 */
void mul(stack_t **stack, unsigned int ln)
{
	int tmp;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	pop(stack, ln);
	(*stack)->n *= tmp;
}

/**
 * mod - mods the top two items on the stack
 * @stack: stack
 * @ln: line number
 */
void mod(stack_t **stack, unsigned int ln)
{
	int tmp;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	pop(stack, ln);
	(*stack)->n %= tmp;
}
