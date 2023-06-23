#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int temp_n;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp_n = temp->n;
	temp->n = temp->next->n;
	temp->next->n = temp_n;
}