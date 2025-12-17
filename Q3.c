#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

#include "Q3.h"

// executes the given command and allows to exit the mini shell

int execute_cmd_final(){
    char buffer_cmd_line[MAX_LINE_SIZE] = {0};
    int nb_char_read = read(STDERR_FILENO, buffer_cmd_line, MAX_LINE_SIZE);
    if(nb_char_read == -1){
        perror("Read");
        exit(EXIT_FAILURE);
    }
    buffer_cmd_line[nb_char_read-1]=0;

    if(strcmp(buffer_cmd_line, "exit") == 0 || buffer_cmd_line[0]=='\0'){ // We can also test n = 0 for the ctrl+D
            exit(EXIT_SUCCESS);
        }
    int process_id = fork();

    if(process_id == 0){        
        if(execlp(buffer_cmd_line, buffer_cmd_line, NULL)==-1){
            perror("Exécution");
            exit(EXIT_FAILURE);
        }
    }

    int status;
    wait(&status);
    return status;
}