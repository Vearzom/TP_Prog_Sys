#ifndef Q5_H
#define Q5_H

#define BUFFER_SIZE 128
#define EXIT_COMMAND "exit"
#define ERROR_READ "Erreur lors de la lecture de la commande\n"
#define ERROR_EXEC "Erreur lors de l'execution de la commande\n"
#define NS_TO_MS 1000
#define S_TO_MS 1000000.0

float execute_command_with_exit(int* status);

#endif