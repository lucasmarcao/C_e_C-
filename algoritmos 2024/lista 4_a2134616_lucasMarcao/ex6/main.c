#include <stdio.h>

int main()
{
    int linhas, i, j;

    printf("Informe o número de linhas do triângulo: ");
    scanf("%d", &linhas);

    if (linhas <= 0)
    {
        printf("Por favor, informe um número de linhas positivo.\n");
        return 1;
    }

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("[]");
        }
        printf("\n");
    }

    return 0;
}
