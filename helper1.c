#include "shell.h"
/**
 * _strlen - length
 * @s: 1
 *
 * Return: int
 */
int _strlen(char *s)
{
	int x;
	int i;

	x = 0;
	for (i = 0; *(s + i) != '\0'; i++)
	{
		x++;
	}
	return (x);
}

/**
* _strcpy - copying the array
* @dest: first input
* @src: second input
*
* Return: char *
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; *(src + i) != '\0'; i++)
	{
		*(dest + i) = *(src + i);
	}
	*(dest + i) = '\0';
	return (dest);
}

/**
 * _strcat - cat
 * @dest: 1
 * @src: 2
 *
 * Return: string
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int x;

	for (i = 0; *(dest + i) != '\0'; i++)
	{
	}
	for (x = 0; *(src + x) != '\0'; x++)
	{
		*(dest + i + x) = *(src + x);
	}
	*(dest + i + x) = '\0';
	return (dest);
}

/**
* _strcmp - copmare two str
* @s1: first input
* @s2: secend input
*
* Return: int
*/
int _strcmp(char *s1, char *s2)
{
	int x;
	int i;

	x = 0;
	for (i = 0; *(s1 + i) != '\0' && *(s2 + i) != '\0'; i++)
	{
		if (*(s1 + i) != *(s2 + i))
		{
			x = (int)*(s1 + i) - (int)*(s2 + i);
			break;
		}
	}
	return (x);
}

/**
* _strdup - array
* @str: string
*
* Return: char
*/
char *_strdup(char *str)
{
	char *x;
	unsigned int i;
	unsigned int size;

	if (str == NULL)
		return (NULL);

	size = strlen(str);
		x = malloc(size * sizeof(*str) + 1);
		if (x == NULL)
		{
			return (NULL);
		}
		else
		{
			for (i = 0; *(str + i); i++)
			{
				*(x + i) = *(str + i);
			}
		}
		return (x);
}
