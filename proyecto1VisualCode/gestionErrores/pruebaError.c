#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    FILE* fichero;
    
    fichero = fopen("./hola.txt", "r");
    if (fichero == NULL) {
        perror("Error abriendo el fichero");
        fprintf(stderr, "Línea: %d -> %s -> Código de error %d. Texto: %s\n", __LINE__, __FILE__, errno, strerror(errno));
    }

    return 0;
}
