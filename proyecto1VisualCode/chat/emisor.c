#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // Para crear la tuberia -> mknod tuberia p
    char *frase;
    pid_t miPid = getpid();

    printf("%d\n", miPid);

    // Escribir de la tubería
    int escritorTuberia = open("./tuberia", O_WRONLY);
    write(escritorTuberia, &miPid, 1 * sizeof(pid_t));
    while(1) {
        printf("Escribe un mensaje: ");
        scanf("%s", frase);
        write(escritorTuberia, frase, (strlen(frase)+1) * sizeof(char)); // strlen da el tamaño del string sin el \0, para enviar el \0 sumamos 1 a strlen
    }
    close(escritorTuberia);

    return 0;
}
