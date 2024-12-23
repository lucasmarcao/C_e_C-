#include <stdio.h>

void print_even(int n, int vet[])
{
    printf("Valores pares: ");
    for (int i = 0; i < n; i++)
    {
        if (vet[i] % 2 == 0)
        {
            printf("%d ", vet[i]);
        }
    }
    printf("\n");
}

int main()
{
    int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(vet) / sizeof(vet[0]);
    print_even(n, vet);
    return 0;
}
