#include "shell.h"
/**
 * _getenv - Gets environment variable
 * @enviro: The wanted variable
 *
 * Return: A pointer to the environment variables or NULL if failled
 */

char *_getenv(char *enviro)
{
	char *tmp, *token, *target;
	int i = 0;

	while (environ[i])
	{
		tmp = strdup(environ[i]);
		token = strtok(tmp, "=");
		if (_strcmp(tmp, enviro) == 0)
		{
			token = strtok(NULL, "\n");
			target = strdup(token);
			free(tmp);
			return (target);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

/**
 * get_path - Gets the path of the command
 * @command: The command
 *
 * Return: A pointer to the full path or NULL if failled
 */
char *get_path(char *command)
{
	char *path, *full_path;
	char *token;
	struct stat s;

	if (stat(command, &s) == 0)
		return (command);

	path = _getenv("PATH");
	token = strtok(path, ":");

	while (token)
	{
		full_path = malloc(sizeof(char) * (_strlen(token) + _strlen(command) + 2));
		if (full_path)
		{
			strcpy(full_path, token);
			strcat(full_path, "/");
			strcat(full_path, command);
			if (stat(full_path, &s) == 0)
			{
				free(path);
				return (full_path);
			}
			free(full_path);
			token = strtok(NULL, ":");
		}
	}

	free(path);
	return (NULL);
}
