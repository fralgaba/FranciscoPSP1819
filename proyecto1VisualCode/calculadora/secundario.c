#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char numero1[100];
    char operador;
    printf("Introduce el primer número: ");
    fgets(numero1, 100, stdin);
    printf("%s", numero1);
    double numero = atof(numero1);
    printf("%lf\n", numero);

    printf("Dame un caracter: ");
    fscanf(stdin, "%c", &operador);
    printf("%c\n", operador);

    return 0;
}
