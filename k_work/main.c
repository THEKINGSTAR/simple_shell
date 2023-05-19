#include "shell.h"

int main(void)
{
	char *s;

	while (1)
	{
	printf("($)");
	s = get_line();
	if (strcmp(s, "exit") == 0)
		break;
	excute(s);
	}
	return (0);
}
