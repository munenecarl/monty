#include "main.h"

/**
 * main - entry point of the program
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line_content;
	unsigned int line_number = 1;
	size_t line_length = 0;
	ssize_t read_line;
	stack_t *stack = NULL;


	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line_number > 0)
	{
		line_content = NULL;
		read_line = _getline(&line_content, &line_length, file);
		if (read_line == -1)
		{
			free(line_content);
			break;
		}
		executor(&stack, line_number, line_content);
		line_number++;
		free(line_content);
	}
	free_stack(stack);
	fclose(file);
	return (0);		
}