#include "monty.h"

/**
 * nop - really doesn't do anything
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
*/

void nop(stack_t stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}