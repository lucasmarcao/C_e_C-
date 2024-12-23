// treino
#include <stdio.h>

int main()
{
    printf("\n\n");
    // espaço estrategico

    /* variable definition: */
    int notaAparencia = 0;
    printf("digite a aparencia dela: ");
    scanf("%d", &notaAparencia);

    switch (notaAparencia)
    {
    case 2:
        printf("cai fora.");
        break;
    case 6:
        printf("da um beijo.");
        break;
    case 10:
        printf("casa com ela.");
        break;
    default:
        printf("default clt.");
        break;
    }

    // espaço estrategico
    printf("\n\n\a");
    return 0;
}