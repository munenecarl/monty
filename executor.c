#include "monty.h"

/**
 * executor - executes the opcode in the monty file
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: 0 if success, 1 if failure
 */

int executor(stack_t **stack, unsigned int line_number, char *line_content)
{
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop}
		{NULL, NULL}
	};
	int i = 0;
	char *opcode;

	opcode = strtok(line_content, " \n\t");
	if (opcode == NULL)
		return (0);
	if (opcode[0] == '#')
		return (0);
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}