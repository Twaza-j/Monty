#include "monty.h"

/* Math operations part 2 */

/**
 * mod - Computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: The stack
 * @line_number: Line number where the mod opcode will be interpreted
 *
 * Return: Nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	unsigned int len = 0;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
		err_handle_more(14, NULL, *stack, NULL, NULL, line_number);

	if ((*stack)->n == 0)
		err_handle_more(12, NULL, *stack, NULL, NULL, line_number);

	(*stack)->next->n = (*stack)->next->n % (*stack)->n;

	pop(stack, line_number);
}
