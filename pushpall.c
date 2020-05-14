#include "monty.h"

/**
 * push - pushes a new node with info to top of the stack
 * @stack: incoming stack
 * @line_number: line number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	/**	extern char *arg;*/
	int i, n;
	char *arg = args[3];

	if (arg == NULL)
	{
		freeall(*stack, (char *)args[0], (FILE *)args[1], *((int *)args[2]));
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; arg[i] != '\0'; i++)
	{
		if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '-')
		{
			freeall(*stack, (char *)args[0], (FILE *)args[1], *((int *)args[2]));
			dprintf(2, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		if (arg[i] == '-' && arg[i + 1] == '\0')
		{
			freeall(*stack, (char *)args[0], (FILE *)args[1], *((int *)args[2]));
			dprintf(2, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

	}
	n = atoi(arg);
	/** new node, call func add node to top */
	addnodeint(stack, n);
}

/**
 * pall - prints all the values on the stack starting from the top
 * @stack: incoming stack
 * @line_number: att unused
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	print_stack_t(*stack);
}

/**
 * print_stack_t - prints elements in a stack
 * @stack: top of stack
 * Return: elements in a stack
 */

void print_stack_t(stack_t *stack)
{
	stack_t *temp;

	temp = stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}

}
