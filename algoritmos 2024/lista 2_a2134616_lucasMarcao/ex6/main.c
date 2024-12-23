#include <stdio.h>
#include <stdint.h>


int main()
{
    int num1, num2, num3, num4, maior;

    // Solicita ao usuário que insira os quatro números inteiros
    printf(" \n Digite o primeiro número inteiro: ");
    scanf("%d", &num1);

    printf("Digite o segundo número inteiro: ");
    scanf("%d", &num2);

    printf("Digite o terceiro número inteiro: ");
    scanf("%d", &num3);

    printf("Digite o quarto número inteiro: ");
    scanf("%d", &num4);

    // Assume que o primeiro número é o maior inicialmente
    maior = num1;

    // Verifica se os outros números são maiores
    if (num2 > maior)
    {
        maior = num2;
    }
    if (num3 > maior)
    {
        maior = num3;
    }
    if (num4 > maior)
    {
        maior = num4;
    }

    // Imprime o maior número
    printf("O maior número digitado é: %d\n", maior);

    return 0;
}
