#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc == 3) {
        char quitarLetra = argv[2][0];
        char caracter;
        FILE *fichero;
        FILE *ficheroCopia;

        fichero = fopen(argv[1], "r"); // Abrimos en modo lectura el fichero introducido por parámetro.
        if (fichero == NULL) { // Si el fichero no existe da un error.
            perror("El fichero introducido no existe...");
            exit(-1);
        }

        ficheroCopia = fopen("./fraseCopia.txt", "w");

        
        while ((caracter = getc(fichero)) != EOF) { // Imprimimos caracter a caracter hasta que lleguemos al final del fichero.
            if (caracter == quitarLetra) {
                putc('_', ficheroCopia);
            }
            else {
                putc(caracter, ficheroCopia);
            }
        }
        fprintf(stdout, "Hecho!\n");
    }
    else {
        fprintf(stdout, "No se ha introducido UN argumento por parámetro...\n./modificarCaracter.c caracter\n");
    }
    return 0;
}
