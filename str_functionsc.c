#include "shell.h"
/**
 *_strcmp - a function that compares two strings.
 *
 *@s1: first string
 *@s2: second string
 *Return: returns an integer
 *
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}


/**
 *_strcat - a function that concatenates two strings.
 *
 *@dest: destination string
 *@src: source string
 *
 *Return: the pointer to dest
 *
 */



char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (*(dest + i) != '\0')
	{
		i++;
	}

	while (j >= 0)
	{
		*(dest + i) = *(src + j);
		if (*(src + j) == '\0')
		break;
		i++;
		j++;
	}
	return (dest);
}


/**
 *_strlen -findes the length of a string
 *
 *@s: the string
 *
 *Return: returens the length of the string
*/
int _strlen(char *s)
{
	int i;
	int len = 0;

	for (i = 0; *(s + i) != '\0'; i++)
		len += 1;
	return (len);
}

/**
  * _strcpy - Copy a string
  * @dest: Destination string
  * @src: Source string
  *
  * Return: the pointer to dest
  */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; *(src + i) != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i++] = '\0';

	return (dest);
}
