#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Q6.h"
#include "Q3.h"


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "Q6.h"
#include <time.h>

char ** execute_complex_cmd(int * argc, char* command){
    char ** args[16];
    char * flag = strtok(command, " ");
    int index = 0;
    while (flag != NULL) {
        args[index++] = flag;
        flag = strtok(NULL, " ");
    }
    args[index] = NULL;
    *argc = index;
    return args;
}  
