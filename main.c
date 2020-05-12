#include "monty.h"

char *arg = NULL;

int main(int argc, char **argv)
{
	int i;
	int fd;
	int arg;
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
		opcode = strtok(line, delim);
		arg = strtok(NULL, delim);

		for (i = 0; i < 2; i++)
		{
			if (strcmp(opcode, codelist[i].opcode) == 0)
			{
				codelist[i].f(&stack, ln);
				break;
			}
		}

		if (i == 2)
		{
			dprintf(2, "L%d: unknown instruction %s", ln, opcode);
			exit(EXIT_FAILURE);
		}
	}

	return (0);
}
