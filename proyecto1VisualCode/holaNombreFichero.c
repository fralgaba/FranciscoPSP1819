#include <stdio.h>
#include <string.h>

void main(int argc, char const *argv[])
{
    /*fprintf(stdout, "Escribe un nombre para saludar: ");
    char nombre[15];
    fscanf(stdin, "%s", nombre);
    fprintf(stdout, "Hola %s. Tu inicial es %c.\n", nombre, nombre[0]); // Una cadena no se pasa por referencia porque es un conjunto de carácteres (vector).*/
    char cadenaSalida[] = "salir";
    char nombre[15];
    
    fprintf(stdout, "Escribe un nombre para saludar: ");
    fscanf(stdin, "%s", nombre);
    while (strcmp(cadenaSalida, nombre) != 0) {
        fprintf(stdout, "Hola %s. Tu inicial es %c.\n", nombre, nombre[0]);
        fscanf(stdin, "%s", nombre);
    }
    fprintf(stdout, "Se escribió la palabra clave %s\n", nombre);
}
