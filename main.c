#include "shell.h"

/**
 * main - Simple shell
 * @ac: Arguments count.
 * @av: Arguments array.
 * Return: Always 0
 */

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	if (isatty(STDIN_FILENO) == 1)
	{
		interactive(av);
	}
	else
	{
		non_interactive(av);
	}
	return (0);
}

/**
 * interactive - Runs the shell in interactve mode
 *
 * @av: Arguments array.
 *
 */
void interactive(char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t d;
	char **tokenized;
	(void)av;

	while (1)
	{
		write(1, "$ ", 2);
		d = getline(&line, &len, stdin);
		if (d == -1)
		{
			write(1, "\n", 1);
			free(line);
			return;
		}
		tokenized = tokenize(line);
		if (check_builtins(tokenized) == 1)
			handle_builtins(tokenized);
		else
			execute(tokenized);
	}
}

/**
 * non_interactive - Runs the shell in non-interactve mode
 *
 *  @av: Arguments array.
 *
 */
void non_interactive(char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t d;
	char **tokenized;
	(void)av;

	while (1)
	{
		d = getline(&line, &len, stdin);
		if (d == -1)
			break;
		tokenized = tokenize(line);
		if (check_builtins(tokenized) == 1)
			handle_builtins(tokenized);
		else
			execute(tokenized);
	}
	free(line);
}

/**
 * check_builtins - Checks for built-ins commands
 *
 * @argv: Arguments array.
 *
 * Return: Returns 1 on success or 0
 */
int check_builtins(char **argv)
{
	char *builtins[] = {"exit", "env", NULL};
	int i;

	if (argv[0] == NULL)
	{
		return (0);
	}
	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(argv[0], builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handle_builtins - Handles builtins (env and exii)
 * @argv: Arguments array.
 *
 */

void handle_builtins(char **argv)
{
	int i = 0;

	if (_strcmp(argv[0], "exit") == 0)
	{
		free(argv);
		exit(127);
	}
	else if (_strcmp(argv[0], "env") == 0)
	{

		while (environ[i])
		{
			write(1, environ[i], _strlen(environ[i]));
			write(1, "\n", 1);
			i++;
		}
	}
	free(argv);
}
