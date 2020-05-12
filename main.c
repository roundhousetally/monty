#include "monty.h"

char *arg = NULL;

int main(int argc, char **argv)
{
	int i;
	int fd;
	int ln = 0;
	FILE *file;
	char *opcode;
	char *line = NULL;
	char *delim = " ";
	size_t linelen = 0;
	stack_t *stack = NULL;
	instruction_t codelist[] = {
				{"push", push},
				{"pall", pall},
				{"pint", pint},
				};

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	file = fdopen(fd, "r");

	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &linelen, file) != -1)
	{
		ln++;
		for (i = 0; line[i] != '\n'; i++)
			;
		line[i] = '\0';
		opcode = strtok(line, delim);
		arg = strtok(NULL, delim);

		for (i = 0; i < 3; i++)
		{
			if (strcmp(opcode, codelist[i].opcode) == 0)
			{
				codelist[i].f(&stack, ln);
				break;
			}
		}

		if (i == 3)
		{
			dprintf(2, "L%d: unknown instruction %s\n", ln, opcode);
			free(line);
			free_stack_t(stack);
			fclose(file);
			close(fd);
			exit(EXIT_FAILURE);
		}
	}
	free_stack_t(stack);
	free(line);
	fclose(file);
	close(fd);
	return (0);
}
