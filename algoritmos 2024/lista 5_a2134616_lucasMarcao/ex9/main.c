#include <stdio.h>

void vector_copy(int n, int vet2[], int vet1[])
{
    for (int i = 0; i < n; i++)
    {
        vet2[i] = vet1[i];
    }
}

int main()
{
    int n = 5; // Tamanho dos vetores
    int vet1[] = {1, 2, 3, 4, 5};
    int vet2[n];

    printf("Vetor original (vet1): ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet1[i]);
    }
    printf("\n");

    vector_copy(n, vet2, vet1);

    printf("Vetor copiado (vet2): ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet2[i]);
    }
    printf("\n");

    return 0;
}
