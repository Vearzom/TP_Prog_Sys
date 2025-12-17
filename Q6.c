#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Q6.h"
#include "Q3.h"

void execute_complex_cmd(char *argv){
    char * buf;
    while((buf = strtok(argv, SEPARATOR)) != NULL){
        
    }

}