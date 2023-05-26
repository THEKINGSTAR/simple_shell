#include "shell.h"

/**
 * _realloc - reallocates a pointer to double the space
 * @ptr_in: pointer to the old array
 * @size: pointer to number of elements in the old array
 *
 * Return: NEW pointer to the new array
 */
char **_realloc(char **ptr_in, int *size)
{
	char **new_ptr;
	int i;

	new_ptr = malloc(sizeof(char *) * ((*size) + 10));
	if (new_ptr == NULL)
	{
		free(ptr_in);
		return (NULL);
	}
	for (i = 0; i < (*size); i++)
	{
		new_ptr[i] = ptr_in[i];
	}
	*size += 10;
	free(ptr_in);
	return (new_ptr);
}
