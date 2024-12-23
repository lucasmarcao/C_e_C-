/*
descrição:
*/
#include <stdio.h>  // scanf()   printf()  FILE
#include <string.h> // strcat() strcat() strcpy()
#include <stdlib.h> // malloc()  size_t  NULL
#include <unistd.h> // Inclua essa biblioteca para usar sleep()

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.

    int tam = strlen("suco de uva"); // len [11]
    printf("%d", tam);               // mostra o tamanho da String.
    sleep(2);                        // Pausa o programa por 2 segundos
    printf("\n 3 segundos");

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}