#include "monty.h"

/**
 * _getline - gets the line from the input buffer
 * @lineptr: pointer to the line to be read
 * @n: size of the line to be read
 * @stream: file to be read
 * Return: pointer to the input buffer 
*/

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t i = 0;
	int c;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return -1;

	if (*lineptr == NULL || *n == 0) 
	{
		*n = 128;  
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		return -1;
	}

	while ((c = fgetc(stream)) != EOF) 
	{
		if (i + 1 >= *n) 
		{  
			size_t new_size = *n + 128;  
			char *new_lineptr = malloc(new_size);
			if (new_lineptr == NULL)
				return -1;

			memcpy(new_lineptr, *lineptr, *n);
			free(*lineptr);

			*lineptr = new_lineptr;
			*n = new_size;
		}

		(*lineptr)[i++] = (char)c;

		if (c == '\n')
			break;
	}

	if (i == 0 && c == EOF)
		return -1;

	(*lineptr)[i] = '\0';
	return i;
}
