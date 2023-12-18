#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to doubly linked list representation of a stack
 * @data: line number in monty bytecode file
 * Return: void
 */
void pop(stack_t **stack, unsigned int data)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack", data);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	*stack = (*stack)->next;

	free(temp);


	if (*stack != NULL)
		(*stack)->prev = NULL;
}
