#include <stdio.h>

int main()
{
    int num1, num2, num3;

    // Solicita ao usuário que insira os três números inteiros
    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &num1);

    printf("Digite o segundo número inteiro: ");
    scanf("%d", &num2);

    printf("Digite o terceiro número inteiro: ");
    scanf("%d", &num3);

    // Ordena os números
    if (num1 > num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if (num2 > num3)
    {
        int temp = num2;
        num2 = num3;
        num3 = temp;

        if (num1 > num2)
        {
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
    }

    // Imprime os números em ordem crescente
    printf("Os números em ordem crescente são: %d, %d, %d\n", num1, num2, num3);

    return 0;
}
