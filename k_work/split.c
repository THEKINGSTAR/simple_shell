/* #include "main.h" */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char **split(char *line)
{
	char **tokens = NULL;
	char *token = strtok(line, " ");
	int count = 0;

	while (token != NULL)
	{
		token = realloc(tokens, (count + 1) * sizeof(char *));
		tokens[count] = malloc(strlen(token + 1));
		strcpy(tokens[count], token);
		count ++;
		token  = strtok (NULL, " ");

	}
	tokens = realloc(tokens , (count + 1) * sizeof(char *));
	tokens[count] = NULL;

	return (tokens);
}

int main() 
{
    char input[100];
    printf("Enter a line: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
   
    char **result = split(input);
    int i = 0;
    while (result[i] != NULL) 
    {
        printf("%s\n", result[i]);
        free(result[i]);
        i++;
    }
    free(result);

    return (0);
}

