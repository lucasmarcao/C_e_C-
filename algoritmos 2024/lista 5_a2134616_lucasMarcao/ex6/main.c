#include <stdio.h>

int is_sorted(int n, int vet[])
{
    for (int i = 1; i < n; i++)
    {
        if (vet[i] < vet[i - 1])
        {
            return 0; // Não está em ordem crescente
        }
    }
    return 1; // Está em ordem crescente
}

int main()
{
    int vet1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(vet1) / sizeof(vet1[0]);

    int vet2[] = {5, 3, 7, 8, 9};
    int n2 = sizeof(vet2) / sizeof(vet2[0]);

    printf("vet1 está em ordem crescente? %s\n", is_sorted(n1, vet1) ? "Sim" : "Não");
    printf("vet2 está em ordem crescente? %s\n", is_sorted(n2, vet2) ? "Sim" : "Não");

    return 0;
}
