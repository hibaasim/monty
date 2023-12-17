#include "monty.h"

/**
 * f_pop - removes node at the top of the stack
 * @stack: the top of the stack
 * @line_number: the line segment
 *
*/
void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_list(*stack);
		fclose(globe.file);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack) = temp->next;
	free(temp);
}

/**
 * f_swap - swaps top two elements in stack
 * @stack: the head node
 * @line_number: the line segmemnt
 *
*/
void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_list(*stack);
		fclose(globe.file);
		exit(EXIT_FAILURE);
	}
	*stack = temp->next;
	temp->next = (*stack)->next;
	temp->prev = (*stack);
	(*stack)->next = temp;
}

/**
 * f_add - adds top two elements
 * @stack: the head node
 * @line_number: the line segment
*/
void f_add(stack_t **stack, unsigned int line_number)
{
	stack_t *add;
	int res;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_list(*stack);
		fclose(globe.file);
		exit(EXIT_FAILURE);
	}
	add = *stack;
	*stack = add->next;
	res = (add->n) + ((*stack)->n);
	(*stack)->n = res;
	free(add);

}
