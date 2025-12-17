#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Q1.h"

#define MESSAGE "Bienvenue dans le Shell ENSEA \nPour quitter, tapez 'exit'.\n"
#define PERMANENT "enseash% "
#define SIZE_MESSAGE 59
#define SIZE_PERMANENT 9

void welcome_message(){
    if(write(STDOUT_FILENO, MESSAGE, SIZE_MESSAGE) == -1){
        perror("Write");
        exit(EXIT_FAILURE);
    }
}

void permanent_message(){
    if(write(STDOUT_FILENO, PERMANENT, SIZE_PERMANENT) == -1){
        perror("Write");
        exit(EXIT_FAILURE);
    }
}