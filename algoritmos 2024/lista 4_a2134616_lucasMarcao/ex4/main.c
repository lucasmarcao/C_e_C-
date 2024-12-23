#include <stdio.h>

int main()
{
    int numero, somaDivisores = 0, i;

    printf("Informe um número inteiro positivo: ");
    scanf("%d", &numero);

    if (numero <= 0)
    {
        printf("Por favor, informe um número inteiro positivo.\n");
        return 1;
    }

    // Calcula a soma dos divisores
    for (i = 1; i < numero; i++)
    {
        if (numero % i == 0)
        {
            somaDivisores += i;
        }
    }

    // Verifica se o número é perfeito
    if (somaDivisores == numero)
    {
        printf("Divisores de %d: 1", numero);
        for (i = 2; i < numero; i++)
        {
            if (numero % i == 0)
            {
                printf(" + %d", i);
            }
        }
        printf(" = %d\n", numero);
        printf("Número perfeito? Sim\n");
    }
    else
    {
        printf("Número perfeito? Não\n");
    }

    return 0;
}
