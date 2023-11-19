#include "monty.h"

/**
 * add - Adds the top two elements of a stack, stores the result in the
 * second top element and removes the top element
 * @stack: The stack
 * @line_number: The line number where add opcode executed
 *
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_ptr;
	unsigned int len = 0;

	temp_ptr = *stack;

	while (temp_ptr != NULL)
	{
		temp_ptr = temp_ptr->next;
		len++;
	}

	if (len < 2)
		err(9, NULL, *stack, NULL, NULL, line_number);

	(*stack)->next->n = (*stack)->next->n + (*stack)->n;

	pop(stack, line_number);
}

/**
 * nop - Doesn’t do anything
 * @stack: The stack
 * @line_number: The line number where nop opcode executed
 *
 * Return: Nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/* Math functions part 1 */
