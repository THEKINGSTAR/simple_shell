#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_PATH 1024

int main() {
    char input[1024];
    char *args[MAX_ARGS];
    char *path = getenv("PATH");
    char *dir;
    char full_path[MAX_PATH];
    int status;
    pid_t pid;

    while (1) {
        // Read user input
        printf("$ ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        // Parse input into arguments
        args[0] = strtok(input, " ");
        int i = 1;
        while (i < MAX_ARGS && (args[i] = strtok(NULL, " ")) != NULL) {
            i++;
        }
        args[i] = NULL;

        // Search for command in PATH
        dir = strtok(path, ":");
        while (dir != NULL) {
            snprintf(full_path, MAX_PATH, "%s/%s", dir, args[0]);
            if (access(full_path, X_OK) == 0) {
                break;
            }
            dir = strtok(NULL, ":");
        }

        // Execute command if found, otherwise print error message
        if (dir != NULL) {
            pid = fork();
            if (pid == 0) {
                execve(full_path, args, NULL);
                perror("execve");
                exit(1);
            } else if (pid == -1) {
                perror("fork");
                exit(1);
            } else {
                wait(&status);
            }
        } else {
            printf("Command not found: %s\n", args[0]);
        }
    }

    return 0;
}
