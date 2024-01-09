#include "shell.h"
/**
 * tokenize - A function that tokenize a string
 * @line: The string to be tokenized
 *
 * Return: Retuns an array of the tokenized strings
 */
char **tokenize(char *line)
{
	char **argv;
	char *token, *copy;
	int count = 0;

	copy = strdup(line);
	token = strtok(copy, "\n \t");
	while (token)
	{
		count++;
		token = strtok(NULL, "\n \t");
	}
	argv = malloc(sizeof(char *) * (count + 1));
	free(copy);
	token = strtok(line, "\n \t");
	for (count = 0; token; count++)
	{
		argv[count] = token;
		token = strtok(NULL, "\n \t");
	}
	argv[count] = NULL;
	return (argv);
}
