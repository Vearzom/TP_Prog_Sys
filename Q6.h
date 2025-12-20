#ifndef Q6_H
#define Q6_H

#define SEPARATOR " "
#define MAX_ARGS 16

char ** passing_cmd(int * argc, char* command);
int execute_cmd_complex(int *argc,char* cmd);

#endif