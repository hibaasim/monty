#include "monty.h"

globe_s globe = {NULL, NULL};
/**
 * exec - executes the functions in the monty file
 * @head: the head of the stack
 * @line_num: the line number
 * @input: the input line
 * @file: the file read from
 *
 * Return: 1 if successful
*/
int exec(stack_t **head, unsigned int line_num, char *input, FILE *file)
{
	instruction_t opera[] = {
					{"push", f_push}, {"pall", f_pall},
					{"pint", f_pint}, {"pop", f_pop},
					{"swap", f_swap}, {"add", f_add},
					{"nop", f_nop}, {NULL, NULL}};
	char *commd, *value;
	int i = 0;

	globe.file = file;
	/*globe.input = input;*/
	commd = strtok(input, " \n\t$");
	if (commd && commd[0] == '#')
		return (0);
	value = strtok(NULL, " \n\t");
	globe.args = value;
	while (opera[i].opcode && commd)
	{
		if (strcmp(commd, opera[i].opcode) == 0)
		{
			opera[i].f(head, line_num);
			return (0);
		}
		i++;
	}
	if (commd && opera[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, commd);
		free(commd);
		free(input);
		free_list(*head);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	return (1);
}
