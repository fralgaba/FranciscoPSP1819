#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void imprimirHolaMundo();
void imprimirEntero(int, char); // No hace falta poner aquí arriba el nombre del parámetro.
void imprimirASCIIHasta(char);

int main(int argc, char const *argv[])
{
    /*char cad1[] = "Hola";
    char cad2[] = " ";
    char cad3[] = "Mundo.";

    char cadRes[7] = "";
    strcat(cadRes, cad1); // Concatenar una cadena con otra.
    strcat(cadRes, cad2);
    strcat(cadRes, cad3);

    fprintf(stdout, "%s\n", cadRes);*/

    // Apundador de memoria.
    char cad1[] = "Hola";
    char cad2[] = " ";
    char cad3[] = "Mundo.";

    int tamTotal = strlen(cad1) + strlen(cad2) + strlen(cad3) + 1; // tamTotal es el total de todas las cadenas más el \0 del final.
    char *cadRes = (char*) malloc(tamTotal * sizeof(char));
    strcat(cadRes, cad1); // Concatenar una cadena con otra.
    strcat(cadRes, cad2);
    strcat(cadRes, cad3);

    fprintf(stdout, "%s %d\n", cadRes, tamTotal);

    imprimirHolaMundo();
    imprimirEntero(45, 75);
    imprimirASCIIHasta('p');
    return 0;
}

void imprimirHolaMundo()
{
    fprintf(stdout, "Hola mundo\n");
}

void imprimirEntero(int a, char b)
{
    fprintf(stdout, "Me has dicho que imprima el entero %d y el carácter %c\n", a, b);
}

void imprimirASCIIHasta(char a)
{
    int i;
    for (i = 0; i <= a; i++) {
        fprintf(stdout, "%c = %d\n", i, i);
    }
}