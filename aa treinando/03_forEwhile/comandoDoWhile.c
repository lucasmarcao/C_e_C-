/*
descrição: faz uma tabuada ai
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.
    int i = 1;
    int tabuadaValor = 0;

    printf("Digite um inteiro: ");
    scanf("%d", &tabuadaValor);

    do 
    // esse comando executa pelo menos uma vez
    // independente se a condição while ta certa.
    {
        int resultadoFinal = tabuadaValor * i;
        printf("\n%d * %d = %d.", i, tabuadaValor, resultadoFinal);
        i = i + 1;
    } while (i <= 10);

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}