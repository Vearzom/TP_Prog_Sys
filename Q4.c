#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Q4.h"

//Displays the status of the command

void print_status(int status, float time){
    char buf[BUF_SIZE];
    
    int temp = snprintf(buf, BUF_SIZE, "%s[%s:%d | %2f]%%", PERMANENT_PROMPT, WIFEXITED(status)?EXIT:SIGNAL,
             WIFEXITED(status)?WEXITSTATUS(status):WTERMSIG(status), time);
    if(write(STDOUT_FILENO, buf, temp) == -1){
        perror("Write");
        exit(EXIT_FAILURE);
    }
          
}