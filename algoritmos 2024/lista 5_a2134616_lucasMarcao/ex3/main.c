#include <stdio.h>

int find_max(int n, int vet[])
{
    int max = vet[0]; // Assume que o primeiro elemento é o maior

    for (int i = 1; i < n; i++)
    {
        if (vet[i] > max)
        {
            max = vet[i];
        }
    }

    return max;
}

int main()
{
    int vet[] = {3, 7, 1, 12, 5, 9};
    int n = sizeof(vet) / sizeof(vet[0]);

    int max = find_max(n, vet);
    printf("O maior valor no vetor é: %d\n", max);

    return 0;
}
