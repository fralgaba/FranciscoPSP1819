#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        printf("Uso del programa:\n\t %s numeroHijos\n", argv[0]);
        exit(-1);
    }

    int numeroHijos = atoi(argv[1]);
    int pidHijo;

    for (int i = 0; i < numeroHijos; i++) {

        pidHijo = fork();

        if (pidHijo == 0) { // Código del hijo
            printf("Soy el hijo número %d\n", i);
            return 0;
        }
    }

    for (int i = 0; i < numeroHijos; i++) {
        wait(NULL);
        printf("PADRE: Un hijo ha acabado...\n");
    }
    return 0;
}
