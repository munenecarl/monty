#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * bus - to strore various global variables - arg, file, line_content, stack
 * @arg: global variable to store the arg
 * @file: global variable to store the file
 * @line_content: global variable to store the line_content
 * @stack: global variable to store the stack
 */

typedef struct bus
{
	FILE *file;
	char *line_content;
	stack_t *stack;
} bus_t;

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int executor(stack_t **stack, unsigned int line_number, char *line_content);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);

#endif