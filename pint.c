#include "monty.h"

/**
 * display_top - prints the value at the top of the stack
 * @stack: pointer to doubly linked list representation of a stack
 * @data: line number in monty bytecode file
 * Return: void
 */
void display_top(stack_t **stack, unsigned int data)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty", data);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
