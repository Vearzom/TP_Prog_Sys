#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Q1.h"


// Displays the welcome message
void welcome_message(){
    if(write(STDOUT_FILENO, MESSAGE, SIZE_MESSAGE) == -1){
        perror("Write");
        exit(EXIT_FAILURE);
    }
}


//Displays the name of the shell
void permanent_message(){
    if(write(STDOUT_FILENO, PERMANENT, SIZE_PERMANENT) == -1){
        perror("Write");
        exit(EXIT_FAILURE);
    }
}