#include <stdio.h>

void replace_all(int n, int vet[], int elem)
{
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == elem)
        {
            vet[i] = -1;
        }
    }
}

int main()
{
    int vet[] = {3, 7, 1, 12, 5, 9, 1};
    int n = sizeof(vet) / sizeof(vet[0]);
    int elem = 1;

    printf("Vetor original: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");

    replace_all(n, vet, elem);

    printf("Após substituição de %d por -1: ", elem);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}
