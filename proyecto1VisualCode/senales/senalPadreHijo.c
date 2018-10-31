#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void tratarSIGINT(int);

int main(int argc, char const *argv[])
{
    printf("Padre: pid: %d\n", getpid());
    pid_t pid;
    signal(SIGINT, tratarSIGINT);
    pid = fork();
    if (pid == -1) {
        perror("Error en el fork");
        exit(-1);
    }
    else if (pid == 0) { // Soy el hijo
        printf("Hijo: pid: %d\n", getpid());
        kill(getppid(), SIGINT);
    }
    else { // Soy el padre
        kill(pid, SIGINT);
        wait(NULL);
    }

    return 0;
}

void tratarSIGINT(int codSenal) {

    fprintf(stdout, "Soy el proceso %d me han enviado una señal.", getpid());
}