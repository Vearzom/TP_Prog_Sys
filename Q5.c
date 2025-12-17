#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "Q5.h"
#include <time.h>


// Executes the command line and displays the execution time and the exit status

float execute_command_with_exit(int* status){  
    struct timespec Start_time;
    struct timespec End_time;
    clock_gettime(CLOCK_REALTIME, &Start_time);                                              // Command Execution
    char buffer_command[BUFFER_SIZE]={0};
    int number_char=read(STDIN_FILENO, buffer_command, BUFFER_SIZE);
   
    if(number_char == -1){
        perror(ERROR_READ);
        exit(EXIT_FAILURE);
    }
    buffer_command[number_char-1]='\0';
    if (strcmp(buffer_command, EXIT_COMMAND)==0 || buffer_command[0]=='\0') { //Exit on 'exit' command or crtl^D
        exit(EXIT_SUCCESS);
    }
    if(fork() == 0){
       
        *status=execlp(buffer_command, buffer_command, NULL);
        if(*status == -1){
            perror(ERROR_EXEC);
            return (-1.0);
        }
        else{
            exit(EXIT_SUCCESS);
            return (0.0);
        }
    }
    wait(status);
    clock_gettime(CLOCK_REALTIME, &End_time);
    float Total_time = abs(End_time.tv_sec - Start_time.tv_sec)/NS_TO_MS + abs(End_time.tv_nsec - Start_time.tv_nsec) / S_TO_MS;
    return(Total_time);
}