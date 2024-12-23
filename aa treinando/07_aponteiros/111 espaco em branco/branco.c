/*

descrição: esse espaço serve pra fazer coisas
aleatorias e testar coisas simples.

*/
#include <stdio.h>  // scanf()   printf()  FILE
#include <string.h> // strcat() strcat() strcpy()
#include <stdlib.h> // malloc()  size_t  NULL
#include <unistd.h> // sleep(segundos)

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