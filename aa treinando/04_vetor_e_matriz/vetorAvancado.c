/*
descrição: faz um bubble sort ai seu otario.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANHO_DO_VETOR(arr) (sizeof(arr) / sizeof((arr)[0]))

void imprimeVetorInt(int vetor[], int tamVetor)
{
    int comeco = 0;
    printf("\n");
    for (comeco; comeco < tamVetor; comeco++)
    {
        printf(" %d ", vetor[comeco]);
    }
}

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.
    int vetorExemplo[] = {3, 5, 2, 1, 6, 4}; // tamanho 6.
    int tamVetor = TAMANHO_DO_VETOR(vetorExemplo);


    // for()

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}