#include "main.h"

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}