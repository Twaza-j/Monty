#include "monty.h"

/**
 * main - Entry point of program
 * @argc: Number of arguments
 * @argv: Array of all arguments
 *
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	FILE *file = NULL;
	char *line = NULL;

	if (argc != 2)
		err(1, line, stack, file, NULL, 0);

	file = fopen(argv[1], "r");
	if (file == NULL)
		err(2, line, stack, file, argv[1], 0);

	process_lines(file, stack);

	return (0);
}
