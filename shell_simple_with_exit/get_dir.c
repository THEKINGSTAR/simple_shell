#include "shell.h"

char *find_file(char *file_name, char **path) {
	int i;
	int flag = 0;
    char *dir_path;
    struct dirent *entry;
    DIR *dir;

    for(i = 0; path[i] != NULL; i++)
    {

    dir = opendir(path[i]);
    if (dir == NULL) {
        perror("opening directory");
        return (NULL);
    }
	
    	while ((entry = readdir(dir)) != NULL) 
	{
        if (entry->d_type == DT_REG && strcmp(entry->d_name, file_name) == 0)
	{
            dir_path = malloc(strlen(path[i]) + strlen(file_name) + 2);
	    if (dir_path == NULL)
	    {
		    perror("allocating memory");
		     
		    closedir(dir);
		    return (NULL);
	    }
	    strcpy(dir_path, path[i]);
	    strcat(dir_path, "/");
	    strcat(dir_path, file_name);
	    flag = 1;
            break;
        }
    	}
	if (flag == 1)
		break;
	}
    if (path[i] == NULL)
    {
	   
	    closedir(dir);
	    return ("0");
    }
    
   
    closedir(dir);
    return (dir_path);
}

