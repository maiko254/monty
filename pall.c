#include "monty.h"

/**
 * display_stack - prints the elements of a stack
 * @top: pointer to doubly linked list representation of a stack
 * @n: line number in monty bytecode file
 * Return: void
 */
void display_stack(stack_t **top, __attribute__((unused)) unsigned int n)
{
	stack_t *temp;

	if (*top != NULL)
	{
		temp = *top;
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}

}
