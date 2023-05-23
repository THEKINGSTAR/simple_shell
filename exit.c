#include "shell.h"

void _exiting(char* line, char** line_splited, char** path)
{
    free(line);
     _free(line_splited);
    _free(path);
    exit(EXIT_SUCCESS);
}
