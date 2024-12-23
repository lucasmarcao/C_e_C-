// treino
#include <stdio.h>

int somadorDeAeB(int a, int b)
{
    int exemplo = a + b;
    return exemplo;
}

int main()
{
    printf("\n\n");
    // espaço estrategico

    /* variable definition: */
    int a = 0;
    int b = 0;

    char chupanigga[50] = "eu odeio laranja.";
    printf("\n %s \n", chupanigga);

    printf("\n Digite o numero que vc quer na soma 1: ");
    scanf("%d", &a);

    printf("\n Digite o numero que vc quer na soma 1: ");
    scanf("%d", &b);

    int result = somadorDeAeB(a, b);
    if (result >= 20 && result != 33)
    {
        printf("\n seu numero é MAIOR que 20 --> %d", result);
    }
    else if (result == 33)
    {
        printf("\n deu 33 essa coisa. ");
    }
    else
    {
        printf("\n seu numero é MENOR que 20 --> %d", result);
    }

    // espaço estrategico
    printf("\n\n\a");
    return 0;
}