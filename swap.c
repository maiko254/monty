#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to doubly linked list representation of a stack
 * @data: line number in monty bytecode file
 * Return: void
 */
void swap(stack_t **stack, unsigned int data)
{
	stack_t *temp1, *temp2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", data);
		exit(EXIT_FAILURE);
	}

	temp1 = *stack;
	temp2 = (*stack)->next;
	
	temp1->next = temp2->next;
	temp1->prev = temp2;
	temp2->next = temp1;
	temp2->prev = NULL;
	
	if (temp1->next != NULL)
		temp1->next->prev = temp1;
	
	*stack = temp2;
}
