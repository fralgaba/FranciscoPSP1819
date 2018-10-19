#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a = 100;
    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error en el fork...\n");
        exit(-1);
    }
    else if (pid == 0) { // Código del hijo
        printf("Hola soy el hijo y mi pid es: %d y el de mi padre es: %d\n", getpid(), getppid());
        sleep(2);
        pid_t pidNieto;
        if (pidNieto = fork() == -1) {
            exit(-1);
        }
        else if (pidNieto == 0) { // Soy el nieto
            printf("Hola soy el nieto y mi pid es: %d y el de mi padre es: %d\n", getpid(), getppid());
        }
        else { // Soy el hijo
            wait(NULL);
            fprintf(stdout, "El nieto ha acabado...\n");  
        }
        printf("Soy un proceso mi pid es: %d\n", getpid()); // Lo imprime el hijo y el nieto
    }
    else { // Código del padre
        fprintf(stdout, "Soy el padre ");
        fprintf(stdout, "y mi pid es: %d %d. El de mi hijo es: %d\n", getpid(), --a, pid);
        wait(NULL); // Espera a que termine el hijo.
        fprintf(stdout, "El hijo ha acabado...\n");
        return 0;
    }
}
