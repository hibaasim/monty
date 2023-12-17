#include "monty.h"

/**
 * main -Entry point(interprets montybyte code)
 * @argc: number of args
 * @argv: list of args
 *
 * Return: Always 0 (Success)
*/
int main(int argc, char *argv[])
{
	char *input;
	FILE *file;
	int line_num = 0;
	ssize_t read = 1;
	size_t input_size = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{
		perror("USAGE: monty file \n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		input = NULL;
		read = getline(&input, &input_size, file);
		if (read != -1)
		{
			line_num++;
			exec(&head, line_num, input, file);
		}
		free(input);
	}
	free_list(head);
	fclose(file);
	return (0);
}
