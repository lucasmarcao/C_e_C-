#include <stdio.h>

void read_vector(int n, int vet[])
{
    printf("Digite os %d números inteiros separados por espaços:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }
}

int main()
{
    int n = 5; // Exemplo: lendo 5 números inteiros
    int vet[n];

    read_vector(n, vet);

    printf("Os números lidos foram: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}
