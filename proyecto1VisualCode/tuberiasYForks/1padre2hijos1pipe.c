#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // Tubería
    int tub[2];
    if (pipe(tub) == -1) {
        exit (-1);
    }
    int entrada = tub[1];
    int salida = tub[0];

    pid_t pidH1, pidH2;

    pidH1 = fork(); // Primer hijo
    if (pidH1 == -1) {
        exit(-2);
    }
    else if (pidH1 == 0) { // Código del hijo 1
        int msj = 123;
        printf("H1: Enviando entero %d por el pipe... ", msj);
        write(entrada, &msj, sizeof(int));
        printf("H1: Hecho\n");
    }
    else { // Codigo del padre
        pidH2 = fork(); // Segundo hijo
        if (pidH2 == -1) {
            exit(-3);
        }
        else if (pidH2 == 0) { // Código del hijo 2
            int msj_recibido = 0;
            printf("H2: Recibiendo entero por el pipe... ");
            read(salida, &msj_recibido, sizeof(int));
            printf("H2: Hecho. He leido %d del pipe\n", msj_recibido);
        }
        else { // Código del padre
            printf("P: Esperando a un hijo... ");
            wait(NULL);
            printf("Hecho\n");
            printf("P: Esperando a un hijo... ");
            wait(NULL);
            printf("Hecho\n");
            close(entrada);
            close(salida);
        }
    }

    return 0;
}
