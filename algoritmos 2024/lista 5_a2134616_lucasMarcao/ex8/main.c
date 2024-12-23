#include <stdio.h>

void reverse(int n, int vet[])
{
    int left = 0;      // Índice do primeiro elemento
    int right = n - 1; // Índice do último elemento

    while (left < right)
    {
        // Troca os elementos nas posições left e right
        int temp = vet[left];
        vet[left] = vet[right];
        vet[right] = temp;

        // Move para os próximos elementos
        left++;
        right--;
    }
}

int main()
{
    int vet[] = {1, 2, 3, 4, 5};
    int n = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");

    reverse(n, vet);

    printf("Vetor invertido: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}
