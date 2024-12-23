#include <stdio.h>

int vector_insert(int n, int vet1[], int elem)
{
    for (int i = 0; i < n; i++)
    {
        if (vet1[i] == -1)
        {
            vet1[i] = elem;
            return 1; // Inserção bem-sucedida
        }
    }
    return 0; // Não há espaço disponível para inserção
}

int main()
{
    int v[9] = {1, 6, -1, 9, 4, -1, -1, 2, -1};
    int size = sizeof(v) / sizeof(v[0]);

    printf("Vetor original: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    int result1 = vector_insert(size, v, 18);
    printf("Resultado da inserção de 18: %s\n", result1 ? "Sucesso" : "Falha");
    printf("Vetor após inserção de 18: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    int result2 = vector_insert(size, v, 7);
    printf("Resultado da inserção de 7: %s\n", result2 ? "Sucesso" : "Falha");
    printf("Vetor após inserção de 7: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
