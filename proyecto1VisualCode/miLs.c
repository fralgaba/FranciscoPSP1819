#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(int argc, char const *argv[])
{
    if (system("ls") == -1) {
        fprintf(stderr, "Error ejecutando el comando...\n");
    }

    fprintf(stdout, "\nAhora con execl:\n");
    execl("/bin/ls", "ls", "-l", (char*) NULL);
}
