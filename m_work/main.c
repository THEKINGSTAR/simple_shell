#include "shell.h"

int main(int argc, char **argv)
{
	char *s;
	char **x;
	int status;

	do
	{
	printf("($) ");
	s = get_line();
	if (strcmp(s, "exit") == 0)
		break;
	x = split(s);
	status = excute(x);
	free(s);
	free(x);
	}while (status);
	
	return (EXIT_FAILURE);
}
