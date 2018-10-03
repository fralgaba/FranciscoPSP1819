#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Pedir 3 string por consola y escribir los 5 primeros carácteres de esos strings en un fichero ejer2.txt, separándolos con saltos de línea
    FILE* fichero = fopen("./ejer2.txt", "w");
    for (int i = 1; i <= 3; i++) 
    {
        char texto[100];
        fprintf(stdout, "Escribe el mensaje %d: ", i);
        scanf("%s", texto);
        fwrite(texto, sizeof(char), 5, fichero);
        putc('\n', fichero);
    }
    fclose(fichero);
    
    return 0;
}
