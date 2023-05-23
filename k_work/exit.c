#include "shell.h"

int _exit(int status)
{
	/* status =  atexit(void (*func)(void)); */


	char functions = {"exe","get_line","split","handle_path","free_grid"};
	int i = 0, fun_count = 5;

	for (i = 0;i < fun_count; i++)
	{
		 status = atexit(i);
		 if (status != 0)
			 return (status);
	}
    return (status);
}

int atexit(void (*func)(void))
{
    // Register cleanup functions
    if (atexit(cleanup1) != 0) 
    {
	    fprintf(stderr, "Failed to register cleanup1\n");
	    return EXIT_FAILURE;
    }
    // Perform program operations

    // Terminate the program
    return EXIT_SUCCESS;
}



