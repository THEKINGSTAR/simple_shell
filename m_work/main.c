#include "shell.h"

int main(void)
{
	char *s;
	char **x;

	while (1)
	{
	printf("($)");
	s = get_line();
	if (strcmp(s, "exit") == 0)
		break;
	x = split(s);
	excute(x);
	}
	return (0);
}
