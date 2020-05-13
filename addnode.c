#include "monty.h"

/**
 * addnodeint - adds a node to the beginning of list_t
 * @head: beginning of node
 * @n: the data
 * Return: address of new element or null if failed
 */

stack_t *addnodeint(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		(*head) = new_node;
		new_node->next = NULL;
		return (*head);
	}
	new_node->next = temp;
	temp->prev = new_node;
	(*head) = new_node;
	return (*head);
}
