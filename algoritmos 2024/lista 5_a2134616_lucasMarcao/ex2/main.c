#include <stdio.h>

void set_positive(int n, int vet[])
{
    for (int i = 0; i < n; i++)
    {
        if (vet[i] < 0)
        {
            vet[i] = -vet[i]; // Inverte o sinal do número negativo
        }
    }
}

int main()
{
    int vet[] = {1, -5, 67, -45, -1, -1, 0, 48};
    int n = sizeof(vet) / sizeof(vet[0]);

    printf("Entrada: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");

    set_positive(n, vet);

    printf("Saída: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}
