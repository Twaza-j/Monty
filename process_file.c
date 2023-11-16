#include "monty.h"
/**
 * process_lines - Process every line
 * @file: File to be processed
 * @stack: A pointer to the stack
 *
 * Return: Nothing
 */
void process_lines(FILE *file, stack_t *stack)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode;

	read = getline(&line, &len, file);

	while (read != -1)
	{
		line_number++;
		opcode = strtok(line, " \n");

		while (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				int value;
				char *argument;

				argument = strtok(NULL, " \n");
				if (argument == NULL || !is_valid_integer(argument))
					err(5, line, stack, file, NULL,line_number);
				value = atoi(argument);
				push(&stack, line_number, value);
			}
			else if (strcmp(opcode, "pall") == 0)
				pall(&stack, line_number);
			else if (strcmp(opcode, "pint") == 0)
				pint(&stack, line_number);
			else
				err(3, line, stack, file, opcode, line_number);
			opcode = strtok(NULL, " \n");
		}
		read = getline(&line, &len, file);
	}
	clean(line, stack, file);
}

/**
 * is_valid_integer - Checks if the argument is a valid integer
 * @argument: The argument to be checked
 *
 * Return: 0 or 1
 */
int is_valid_integer(const char *argument)
{
	while (*argument)
	{
		if (!isdigit(*argument))
		{
			return (0);
		}
		++argument;
	}
	return (1);
}
