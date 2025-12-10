#include <stdlib.h>
#include "Q1.h"
#include "Q2.h"

int main(){
    welcome_message();
    while(1){
        execute_cmd();
    }
    
    exit(EXIT_SUCCESS);
}