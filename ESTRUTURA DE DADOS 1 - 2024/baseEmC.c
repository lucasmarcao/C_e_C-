/*
descrição: XXXxxxxXXX
*/
#include <stdio.h>
// scanf("%d", &inteiro);
#include <string.h>
// strcat("Eu te ", " amo.");
#include <stdlib.h>
// p = (int *)malloc(sizeof(int));

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.

    char frase[] = "suco de uva";
    int tam = strlen(frase);
    // len [11]
    printf("%d \n", tam);

    for (int i = 0; i < tam; i++)
    {
        printf("%c", frase[i]);
    }

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}