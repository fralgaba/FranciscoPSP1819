#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("Hola 1\n");
    fork();
    printf("Hola 2\n");
    fflush(stdout);
    sleep(1);
    return 0;
}
