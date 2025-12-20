#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "Q6.h"
#include <time.h>

char ** parsing_cmd(int * argc, char* command){
    static char *args[MAX_ARGS];
    char *flag = strtok(command, SEPARATOR);
    int index = 0;
    while (flag != NULL && index < MAX_ARGS - 1) {
        args[index++] = flag;
        flag = strtok(NULL, SEPARATOR);
    }
    args[index] = NULL;
    *argc = index;

    return args;
} 

void execute_cmd(char *command) {
    int argc;
    char **args = parsing_cmd(&argc, command);

    if (argc == 0) return;  // nothing to execute

    pid_t pid = fork();  // create a child process
    if (pid < 0) {
        perror("fork failed");
        return;
    }

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) < 0) {
            perror("execvp failed");
            exit(1);
        }
    } else {
        // Parent process waits for child to finish
        int status;
        waitpid(pid, &status, 0);
    }
}
