#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr_malloc, *arr_calloc;
    int n = 5;

    // Alocação com malloc (memória não inicializada)
    arr_malloc = (int *)malloc(n * sizeof(int));
    if (arr_malloc == NULL)
    {
        printf("Erro ao alocar memória com malloc.\n");
        return 1;
    }

    // Alocação com calloc (memória inicializada para zero)
    arr_calloc = (int *)calloc(n, sizeof(int));
    if (arr_calloc == NULL)
    {
        printf("Erro ao alocar memória com calloc.\n");
        free(arr_malloc);
        return 1;
    }

    printf("Memória alocada com malloc: [ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr_malloc[i]); // Valores não inicializados
    }
    printf(" ]");

    printf("\nMemória alocada com calloc: [ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr_calloc[i]); // Valores inicializados a zero
    }
    printf(" ]");
    printf("\n");

    free(arr_malloc);
    free(arr_calloc);

    return 0;
}
