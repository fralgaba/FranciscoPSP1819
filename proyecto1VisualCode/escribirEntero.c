#include <stdio.h>

int main(int argc, char const *argv[])
{
    int entero = 1;
    FILE* fichero = fopen("./escribirEntero.txt", "wb");
    fwrite(&entero, 1, sizeof(int), fichero);
    fclose(fichero);

    return 0;
}
