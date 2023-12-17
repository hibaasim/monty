#include "monty.h"

/**
 * f_push - adds a node to the linked list
 * @stack: the node address
 * @line_number: the number of lines
 *
*/
void f_push(stack_t **stack, unsigned int line_number)
{
	int i = 0, num;
	char *args;

	args = globe.args;
	if (args)
	{
		if (args[0] == '-')
			i++;
		for (; args[i] != '\0'; i++)
		{
			if (args[i] > 57 && args[i] < 48)
			{
				fprintf(stderr, "L%d: usage: push integer ", line_number);
				free_list(*stack);
				fclose(globe.file);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer ", line_number);
		fclose(globe.file);
		exit(EXIT_FAILURE);
	}
	num = atoi(args);
	push(stack, num);
}

/**
 * f_pall - prints all elemnts of a node
 * @stack: the node to be freed
 * @line_number: the line segment
 *
*/
void f_pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	pall(*stack);
}

/**
 * f_pint - prints value at the top of the stack
 * @stack: head of stack
 * @line_number: the line segment
 *
*/
void f_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * f_nop - does nothing
 * @stack: top of stack
 * @line_number: the line segment
 *
*/
void f_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
