#include "monty.h"

/**
 * push_stack - pushes an element to the stack
 * @top: pointer to doubly linked list representation of a stack
 * @data: line number in monty bytecode file
 * Return: void
 */
void push_stack(stack_t **top, unsigned int data)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = data;
	newnode->prev = NULL;
	newnode->next = NULL;

	if (*top == NULL)
	{
		*top = newnode;
	}
	else
	{
		newnode->next = *top;
		(*top)->prev = newnode;
		*top = newnode;
	}
}

/**
 * is_integer - checks if an array of characters is an integer
 * @str: pointer to a atring
 * Return: 0 if str is not an integer 1 otherwise
 */
int is_integer(char *str)
{
	if (*str == '+' || *str == '-')
	{
		str++;
	}

	if (!*str)
		return (0);

	while (*str)
	{
		if (!isdigit((unsigned char)*str))
		{
			return (0);
		}
		str++;
	}

	return (1);
}
