#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char fraseLeida[100];
    pid_t pidEmisor;
    
    // Leer de la tubería
    int lectorTuberia = open("./tuberia", O_RDONLY);
    if (lectorTuberia == -1){
        perror("Open tubería");
        exit(-1);
    }
    read(lectorTuberia, &pidEmisor, 1 * sizeof(pid_t));
    printf("%d\n", pidEmisor);
    while (1) {
        int bytesLeidos = read(lectorTuberia, fraseLeida, 100 * sizeof(char));
        if (bytesLeidos == -1) {
            perror("Read tubería");
            exit(-2);
        }

        printf("%s\n", fraseLeida);

        // Escribir fichero
        /*char escribirCaracter;
        FILE *fichero = fopen("./conversacion.txt", "a");
        for (int i = 0; i < strlen(fraseLeida); i++) {
            putc(fraseLeida[i], fichero);
        }
        putc('\n', fichero);
        fclose(fichero);*/
    }
    close(lectorTuberia);

    return 0;
}
