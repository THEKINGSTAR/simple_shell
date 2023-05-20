#include "shell.h"

int main(int argc, char **argv)
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
