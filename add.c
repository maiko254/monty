#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to doubly linked list representation of a stack
 * @data: line number in monty bytecode file
 */
void add(stack_t **stack, unsigned int data)
{
	stack_t *temp;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short", data);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;

	*stack = (*stack)->next;

	free(temp);

	if (*stack != NULL)
		(*stack)->prev = NULL;
}
