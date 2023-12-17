#include "monty.h"

/**
 * push - adds a new node
 * @head: head node
 * @n: data to be entered
 *
 * Return: address to new node
*/
void push(stack_t **head, int n)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	new->n = n;
	new->next = temp;
	new->prev = NULL;
	if (temp != NULL)
		temp->prev = new;
	(*head) = new;
}

/**
 * free_list - frees the doubly linked list
 * @stack: the node to be freed
 *
*/
void free_list(stack_t *stack)
{
	stack_t *tmp = stack;

	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

/**
 * pall - prints all elements of the liked list
 * @head: the head node
 *
*/
void pall(stack_t *head)
{
	stack_t *st;

	st = head;
	if (st == NULL)
		return;
	while (st != NULL)
	{
		printf("%d\n", st->n);
		st = st->next;
	}
}
