#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int pPadreHijo[2];
    int pHijoPadre[2];
    
    pipe(pPadreHijo);
    pipe(pHijoPadre);

    pid_t pid;
    pid = fork();

    // El hijo empieza leyendo.
    if (pid == 0) { // Código hijo
        close(pPadreHijo[1]); // Cierro la escritura del pipe PadreHijo
        close(pHijoPadre[0]); // Cierro la lectura del pipe HijoPadre

        int recibido;
        read(pPadreHijo[0], &recibido, sizeof(int));
        printf("Hijo: Leído %d del pipe.\n", recibido);

        int enviar = 54321;
        write(pHijoPadre[1], &enviar, sizeof(int));
    }
    else { // Código padre
        close(pPadreHijo[0]); // Cierro la lectura del pipe PadreHijo
        close(pHijoPadre[1]); // Cierro la escritura del pipe HijoPadre

        int enviar = 12345;
        write(pPadreHijo[1], &enviar, sizeof(int));

        int recibido;
        read(pHijoPadre[0], &recibido, sizeof(int));
        printf("Padre: Leído %d del pipe.\n", recibido);

        wait(NULL);
    }
    return 0;
}
