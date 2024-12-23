#include <stdio.h>

int main()
{
    int numero, resto, binario = 0, casaDecimal = 1;

    printf("Informe um número inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 0)
    {
        printf("Por favor, informe um número inteiro positivo.\n");
        return 1;
    }

    while (numero > 0)
    {
        resto = numero % 2;
        binario = binario + resto * casaDecimal;
        casaDecimal *= 10;
        numero /= 2;
    }

    printf("O número em notação binária é: %d\n", binario);

    return 0;
}
