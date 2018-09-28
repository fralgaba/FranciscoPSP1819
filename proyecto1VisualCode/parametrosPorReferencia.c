#include <stdio.h>

void main(int argc, char const *argv[])
{
    int entero;
    fprintf(stdout, "Escribe un entero: ");
    fscanf(stdin, "%d", &entero); // Pasas el entero por referencia (&) (dirección de memoria).
    fprintf(stdout, "El entero es %d y se encuentra en la dirección de memoria %ld\n", entero, &entero);
}