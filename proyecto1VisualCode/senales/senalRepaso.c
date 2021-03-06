#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void tratarSenyal(int);

int main(int argc, char const *argv[])
{
    signal(SIGUSR1,tratarSenyal);
    signal(SIGINT,tratarSenyal);
    int i = 0;
    while (i<100){
        printf("%d\n",++i);
        sleep(1);
    }
    return 0;
}

void tratarSenyal(int numSenyal){
    printf("He recibido una señal con número %d\n",numSenyal);
    fflush(stdout); // Imprime el stdout en el momento de llegar a esta línea
    sleep(1);
}

/*
killall -9 senalRepaso (mata un proceso por su nombre)
killall -SIGKILL senalRepaso (lo mismo que la línea de arriba)

ps -e | grep senalRepaso -> numeroProceso (muestra solo los procesos con nombre senalRepaso)
kill -SIGUSR1 numeroProceso
*/
