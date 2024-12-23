#include <stdio.h>

int main()
{
    int altura, largura, i, j;

    printf("Informe a altura e a largura da caixa (separadas por espaço): ");
    scanf("%d %d", &altura, &largura);

    if (altura <= 0 || largura <= 0)
    {
        printf("Por favor, informe dimensões positivas.\n");
        return 1;
    }

    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            printf("[]");
        }
        printf("\n");
    }

    return 0;
}
