#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Pedir un string por consola y escribir los 4 primeros carácteres de ese string en un fichero ejer1.txt
    FILE* fichero = fopen("./ejer1.txt", "w");
    char texto[100];
    fprintf(stdout, "Escribe un mensaje: ");
    scanf("%s", texto); // Problema con los espacios con scanf.
    fwrite(texto, sizeof(char), 4, fichero);
    fclose(fichero);
    
    return 0;
}
