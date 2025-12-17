#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "Q4.h"


#define PERMANENT "enseash "
#define SIZE_PERMANENT 9
#define BUF_SIZE 128
#define EXIT "exit"
#define SIGNAL "signal"

void print_status(int status){
    char buf[BUF_SIZE];
    
    int temp=snprintf(buf, BUF_SIZE, "%s[%s:%d]%%", PERMANENT, WIFEXITED(status)?EXIT:SIGNAL,
             WIFEXITED(status)?WEXITSTATUS(status):WTERMSIG(status));
    if(write(STDOUT_FILENO, buf, temp) == -1){
        perror("Write");
        exit(EXIT_FAILURE);
    }
          
}