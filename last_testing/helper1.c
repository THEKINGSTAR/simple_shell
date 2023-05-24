#include "shell.h"

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);

p = malloc(new_size);
if (!p)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}

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

void _puts(char *str)
{
	int i;

	for (i = 0; *(str + i) != '\0'; i++)
	{
		_putchar(*(str + i));
	}
	
}

int _strcmp(char *str1,char *str2)
{
    int i=0,diff;
    while(str1[i]!='\0' || str2[i]!='\0')
    {
        diff=str1[i]-str2[i];
         if(diff!=0)
            break;
         i++;
    }
    return diff;
}

int _putchar(char c)
{
	return (write(1, &c, 1));
}

