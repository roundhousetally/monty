#include "monty.h"

char *arg = NULL;

/**
 * main - finds the correct function to run based on commands given
 * @argc: num of args
 * @argv: array of args
 *
 * Return: 0 if no error
 */
int main(int argc, char **argv)
{
	int fd;
	unsigned int i, ln = 0;
	FILE *file;
	char *opcode, *line = NULL, *delim = " ";
	size_t linelen = 0;
	stack_t *stack = NULL;
	instruction_t codelist[] = {
				{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
				{"swap", swap}, {"nop", nop}
				};

	if (argc != 2)
		error(NULL, ln, 'u');
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(argv[1], ln, 'f');
	file = fdopen(fd, "r");
	while (getline(&line, &linelen, file) != -1)
	{
		ln++;
		for (i = 0; line[i] != '\n' && line[i] != '\0'; i++)
			;
		line[i] = '\0';
		opcode = strtok(line, delim);
		arg = strtok(NULL, delim);
		for (i = 0; i < 6; i++)
		{
			if (strcmp(opcode, codelist[i].opcode) == 0)
			{
				codelist[i].f(&stack, ln);
				break;
			}
		}
		if (i == 6)
			freeall(stack, line, file, fd), error(opcode, ln, 'i');
	}
	freeall(stack, line, file, fd);
	return (0);
}

/**
 * freeall - frees everything
 * @stack: stack
 * @line: line buffer
 * @file: file pointer
 * @fd: file descriptor
 */
void freeall(stack_t *stack, char *line, FILE *file, int fd)
{
	free_stack_t(stack);
	free(line);
	fclose(file);
	close(fd);
}

/**
 * error - throws and error
 * @str: string for error
 * @ln: line number
 * @c: error type
 */
void error(char *str, unsigned int ln, char c)
{
	if (c == 'i')
		dprintf(2, "L%d: unknown instruction %s\n", ln, str);
	else if (c == 'f')
		dprintf(2, "Error: Can't open file %s\n", str);
	else if (c == 'u')
		dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
