#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Q1.h"

#define SHELL_NAME "enseash %"
#define MESSAGE "Bienvenue dans le Shell ENSEA \nPour quitter, tapez 'exit'. \nenseash%"
#define SIZE_MESSAGE 68

void welcome_message(){

    if(write(STDOUT_FILENO, MESSAGE, SIZE_MESSAGE) == -1){
        perror("Write");
        exit(EXIT_FAILURE);
    }

    close(STDOUT_FILENO);
    exit(EXIT_SUCCESS);
}