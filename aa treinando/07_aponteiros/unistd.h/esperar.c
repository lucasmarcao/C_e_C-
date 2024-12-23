/*
descrição: essa poha serve pra esperar
*/
#include <stdio.h>  // scanf()   printf()  FILE
#include <unistd.h> // Inclua essa biblioteca para usar sleep()

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.

    printf("espera ");
    sleep(2); // Pausa o programa por 2 segundos
    printf("\n 3 segundos");

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}