#include <stdlib.h>
#include <stdio.h>
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"

int main(){
    int status;
    welcome_message();
    permanent_message();
    while(1){
        //execute_cmd();
        status = execute_cmd_final();
        print_status(status);
    }
    exit(EXIT_SUCCESS);
}