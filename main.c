#include <stdlib.h>
#include <stdio.h>
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"
#include "Q5.h"

#define INIT 0

int main(){
    int status = INIT;
    int time_ms = INIT;
    welcome_message();
    permanent_message();
    while(1){
        //execute_cmd();
        float time_taken = execute_command_with_exit(&status);
        print_status(status, time_taken);
    }
    exit(EXIT_SUCCESS);
}