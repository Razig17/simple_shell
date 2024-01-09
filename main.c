#include "shell.h"

/**
 * main - Dose nothing
 * @ac: Arguments count.
 * @av: Arguments array.
 * Return: Always 0
 */

int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t d;

	(void)ac;
	(void)av;
	if (isatty(STDIN_FILENO) == 1)
	{
		while (1)
		{
			printf("$ ");
			d = getline(&line, &len, stdin);
			if (d == -1)
			{
				printf("\n");
				free(line);
				return (0);
			}
			execute(tokenize(line));
		}
	}
	else
	{
		while (1)
		{
			d = getline(&line, &len, stdin);
			if (d == -1)
				break;
			execute(tokenize(line));
		}
		free(line);
		return (0);
	}
}
