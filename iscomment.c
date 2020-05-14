#include "monty.h"

/**
 * iscomment - checks if arg is a comment and continues
 * @line: line to check for comms
 * Return: 0 if false, 1 if true
 */

int iscomment(char *line)
{
	int i;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '#')
			return (1);
		if (line[i] == ' ')
			continue;
		else
			return (0);
	}
	return (1);
}
