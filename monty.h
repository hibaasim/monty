#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
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

/**
 * struct keys - needed global keys
 * @args: the arguments(values)
 * @file: the opened file
 *
 * Description: the gloabl values needed in different funcs
*/
typedef struct keys
{
	/*char *input;*/
	char *args;
	FILE *file;
} globe_s;

extern globe_s globe;

void f_push(stack_t **stack, unsigned int line_number);
void f_pall(stack_t **stack, unsigned int line_number);
void f_pint(stack_t **stack, unsigned int line_number);
void f_pop(stack_t **stack, unsigned int line_number);
void f_swap(stack_t **stack, unsigned int line_number);
void f_add(stack_t **stack, unsigned int line_number);
void f_nop(stack_t **stack, unsigned int line_number);
void pall(stack_t *head);
void push(stack_t **head, int n);
void free_list(stack_t *stack);
int exec(stack_t **head, unsigned int line_num, char *input, FILE *file);


#endif
