/*
descrição: faça um programa que ordena o vetor
do menor pro maior.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANHO_DO_VETOR(arr) (sizeof(arr) / sizeof((arr)[0]))

void imprimeVetorFloat(float vetor[], int tamVetor)
{
    int comeco = 0;
    printf("\n");
    for (comeco; comeco < tamVetor; comeco++)
    {
        printf(" %.2f ", vetor[comeco]);
    }
}

void ordenaVetorCrescente(float vetor[], int tamVetor)
{
    float armazena = vetor[0];
    float novoVetor[tamVetor];
    for (int i = 0; i < tamVetor - 1; i++)
    {
        // Encontra o menor elemento na parte não ordenada
        int min_idx = i;
        for (int j = i + 1; j < tamVetor; j++)
        {
            if (vetor[j] < vetor[min_idx])
            {
                min_idx = j;
            }
        }

        // Troca o menor elemento encontrado com o primeiro elemento
        float temp = vetor[min_idx];
        vetor[min_idx] = vetor[i];
        vetor[i] = temp;
    }
    // Imprime o vetor ordenado
    imprimeVetorFloat(vetor, tamVetor);
}

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.
    float alturas[] = {
        1.75,
        1.84,
        1.02,
        1.93,
        1.20};
    int tamVetor = TAMANHO_DO_VETOR(alturas);
    // imprime eles desordenados
    imprimeVetorFloat(alturas, tamVetor);

    // ordem certa {}.
    ordenaVetorCrescente(alturas, tamVetor);

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}