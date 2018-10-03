#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // Pedir 2 strings por consola y escribirlos enteros (strlen) en un fichero ejer3.txt, separándolos con 2 saltos de línea
    FILE* fichero = fopen("./ejer3.txt", "w");
    for (int i = 0; i < 2; i++)
    {
        char texto[100];
        fprintf(stdout, "Escribe el mensaje %d: ", i + 1);
        scanf("%s", texto);
        fwrite(texto, sizeof(char), strlen(texto), fichero);
        fwrite("\n\n", sizeof(char), 2, fichero);
    }
    fclose(fichero);

    return 0;
}
