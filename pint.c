#include "monty.h"

void pint(stack_t **stack, const unsigned int ln __attribute__((unused)))
{
	printf("%d\n", (*stack)->n);
}
