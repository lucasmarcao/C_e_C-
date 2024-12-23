/*
descrição: Escreva uma função que recebe o comprimento e o endereço
de um vetor, e imprime o seu conteúdo, sem utilizar o operador
de índice [ ] para acessar os elementos do vetor.
void print_vector(int n, const int* v)

*/
#include <stdio.h>
#include <string.h> // strcat()
#include <stdlib.h> // malloc()

void print_vector(int n, const int *v)
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

    int vetor[] = {4, 6, 8, 1};
    int tamanhovetor = sizeof(vetor) / sizeof(int);

    print_vector(tamanhovetor, vetor);

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}