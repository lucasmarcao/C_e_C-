/*

descrição:  Escreva uma função que recebe o comprimento e o endereço
de um vetor. A função deve retornar, via parâmetros min e max,
o maior e o menor valor contido no vetor. Você não deve utilizar o
operador de índice [ ] para acessar os elementos do vetor.
void get_min_max(int n, const int* v, int* min, int* max)

*/
#include <stdio.h>
#include <string.h> // strcat()
#include <stdlib.h> // malloc()

void get_min_max(int n, const int *v, int *min, int *max)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printf(" %d , ", *v);
            v++;
        }
        else if (i == (n - 1))
        {
            printf(" %d ", *v);
            v++;
        }
        else
        {
            printf(" %d, ", *v);
            v++;
        }
    }
}

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.

    int vetor[][2] = {{3, 6}, {4, 1}, {3, 8}};

    // Tamanho de toda a matriz em bytes
    int size_of_array = sizeof(vetor);

    // Tamanho de um elemento em bytes
    int size_of_element = sizeof(vetor[0][0]);

    // Número total de elementos
    int num_elements = size_of_array / size_of_element;

    printf("Número total de elementos: %d\n", num_elements);

    return 0;

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}