#include "shell.h"
/**
 * execute - A function that executes the commands
 * @argv: Tokenaized arguments
 */
void execute(char **argv)
{
	pid_t pid;

		if (argv[0] == NULL)
	{
		free(argv);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
			free(argv);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}

	free(argv);
}
