/*
descrição:
*/
#include <stdio.h>  // printf("string")
#include <string.h> // strcat()
#include <stdlib.h> // malloc()

void criaDepoisPrintaVetor(int tamVetor, const int *vetor)
{
    int reservaVetor[tamVetor];

    // Copia os elementos manualmente para o clone
    for (int i = 0; i < tamVetor; i++)
    {
        reservaVetor[i] = vetor[i];
    }

    printf("\n");
    for (int i = 0; i < tamVetor; i++)
    {
        if (i == 0)
        {
            printf("vetor = [");
        }
        if (i == (tamVetor - 1))
        {
            printf(" %d ];\n", reservaVetor[i]);
        }
        else
        {
            printf(" %d ,", reservaVetor[i]);
        }
    }
}

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.

    int condicao = 50;
    int vetor[] = {5, 9, 9, 98, 11, 400};
    int tamVetor = (sizeof(vetor) / sizeof(int));

    criaDepoisPrintaVetor(tamVetor, vetor);

    // int borabill = 0;
    // while (condicao == 0)
    // {
    //     int babidi = 0;
    //     printf("\nDigite um inteiro:\n");
    //     scanf("%d", &babidi);
    //     borabill = borabill + babidi;
    //     printf("bora bil == %d", borabill);
    // }

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}