#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

void push_stack(stack_t **top, unsigned int n);
void display_stack(stack_t **top, unsigned int n);
void display_top(stack_t **stack, unsigned int data);
void pop(stack_t **stack, unsigned int data);
void swap(stack_t **stack, unsigned int data);
void add(stack_t **stack, unsigned int data);
void nop(stack_t **stack, unsigned int data);
char *removenewline(char *str);
int is_integer(char *str);

#endif
