#include <stdio.h>

void vector_remove(int n, int vet1[], int pos)
{
    if (pos < 0 || pos >= n)
    {
        printf("Posição inválida. Nenhuma operação realizada.\n");
        return;
    }

    if (vet1[pos] != -1)
    {
        vet1[pos] = -1;
        printf("Elemento removido da posição %d.\n", pos);
    }
    else
    {
        printf("Posição já está vazia. Nenhuma operação realizada.\n");
    }
}

int main()
{
    printf("\n \n");
    int v[9] = {1, 6, -1, 9, 4, -1, -1, 2, -1};
    int size = sizeof(v) / sizeof(v[0]);

    printf("Vetor original: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    vector_remove(size, v, 2);
    printf("Vetor após remoção da posição 2: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    vector_remove(size, v, 4);
    printf("Vetor após remoção da posição 4: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    vector_remove(size, v, 10);

    return 0;
}
