#include "monty.h"
#include "stack_init.h"
#include <stdio.h>

/**
 * main - executes opcodes read from monty bytecode file
 * @argc: number of arguments passed to the program
 * @argv: pointer to array of arguments passed to the program
 * Return: Always 0
 */

stack_t **stack = NULL;

int main(int argc, char **argv)
{
	instruction_t instr[] = {
		{"push", push_stack},
		{"pall\n", display_stack},
		{"pint\n", display_top},
		{"pop\n", pop},
		{"swap\n", swap},
		{"add\n", add},
		{"nop\n", nop},
		{NULL, NULL}
	};

	char *line, *filename;
	FILE *fp;
	size_t n;
	char *opcode, *num, *str;
	unsigned int a, i;
	unsigned int ln;
	int found;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stack = malloc(sizeof(stack_t *));
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	*stack = NULL;

	filename = argv[1];
	line = NULL;
	n = 0;
	ln = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &n, fp) != -1)
	{
		ln++;
		opcode = strtok(line, " ");
		num = strtok(NULL, " ");
		str = strtok(num, "\n");
		if (str != NULL && !is_integer(str))
		{
			fprintf(stderr, "L%u: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
		if (str != NULL)
			a = atoi(str);
		else
			a = 0;

		found = 0;
		i = 0;
		while (instr[i].opcode != NULL && found == 0)
		{
			if (strcmp(opcode, instr[i].opcode) == 0)
			{
				found = 1;
				instr[i].f(stack, a);
			}
			i++;
		}
		if (found == 0)
		{
			fprintf(stderr, "L%u: unknown instruction %s", ln, opcode);
			exit(EXIT_FAILURE);
		}
	}

	fclose(fp);
	free(line);
	free(*stack);
	free(stack);
	return (0);
}
