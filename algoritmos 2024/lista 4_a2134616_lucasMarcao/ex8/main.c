#include <stdio.h>

int main()
{
    int linhas, i, j, espacos;

    printf("Informe o número de linhas do triângulo: ");
    scanf("%d", &linhas);

    if (linhas <= 0)
    {
        printf("Por favor, informe um número de linhas positivo.\n");
        return 1;
    }

    // Para centralizar o triângulo, calculamos o número de espaços a serem impressos antes de cada linha
    espacos = linhas - 1;

    for (i = 0; i < linhas; i++)
    {
        // Imprime espaços em branco antes de cada linha
        for (j = 0; j < espacos; j++)
        {
            printf(" ");
        }
        // Imprime os caracteres '[]'
        for (j = 0; j <= i; j++)
        {
            printf("[]");
        }
        printf("\n");
        // Decrementa o número de espaços em branco para a próxima linha
        espacos--;
    }

    return 0;
}
