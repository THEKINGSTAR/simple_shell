#include "shell.h"

int main()
{
	char *y;
	char **x;
	char *u = getenv("PATH");
	char **w = split_path(u);
	

	while(1)
	{
		printf("($) ");
		y = read_line_by_char();
		x = split(y);
		
		if (strcmp(x[0], "exit") == 0)
		{
			_exiting(y, x, w);
		}

		exe(x, w);	
		_free(x);
		free(y);
	}
	return 0;
}