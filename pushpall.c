#include "monty.h"

void *pall(stack_t **stack, unsigned int line_number __attribute__((unused)));
void print_stack_t(const stack_t *stack);

/**
 * push - pushes a new node with info to top of the stack
 * @stack - incoming stack
 * @line_number - line number
 * Return: void
 */

void *push(stack_t **stack, unsigned int line_number)
{
	/** new node, call func add node to top */
	stack_t *newnode = addnodeint(**stack, line_number);

	/** incre top to point at empty space */
	newnode->next = *stack;
	/** top of stack is new pushed node */
	*stack = newnode;

}

/**
 * pall - prints all the values on the stack starting from the top
 * @stack - incoming stack
 * @line_number - data
 * Return: void
 */

void *pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	print_stack_t(*stack);
}

/**
 * print_stack_t - prints elements in a stack
 * @h: top of stack
 * Return: elements in a stack
 */

void print_stack_t(const stack_t *stack)
{
	const stack_t *temp;

	temp = stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}

}
