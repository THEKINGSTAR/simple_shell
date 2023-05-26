#include "shell.h"

size_t _strncmp(char *s1, char *s2, size_t n)
{
        size_t i, j;

        for (j = 0; s1[j] != '\0' && j < n; j++)
        {
                i = s1[j] - s2[j];

                if (i != 0)
                {
                        return (i);
                }
        }
        return (0);
}

char *_get_path(char **env)
{
	size_t index = 0, var = 0, count = 5;
	char *path = NULL;

	for (index = 0; _strncmp(env[index], "PATH=", 5); index++)
		;
	if (env[index] == NULL)
		return (NULL);

	for (count = 5; env[index][var]; var++, count++)
		;
	path = malloc(sizeof(char) * (count + 1));

	if (path == NULL)
		return (NULL);

	for (var = 5, count = 0; env[index][var]; var++, count++)
		path[count] = env[index][var];

	path[count] = '\0';
	return (path);
}
