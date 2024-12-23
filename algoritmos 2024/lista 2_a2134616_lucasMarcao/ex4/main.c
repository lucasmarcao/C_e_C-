#include <stdio.h>

int main()
{
    int ano;

    // Solicita ao usuário que insira um ano
    printf("Digite um ano: ");
    scanf("%d", &ano);

    // Verifica se o ano é bissexto de acordo com as regras
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
    {
        printf("%d é um ano bissexto.\n", ano);
    }
    else
    {
        printf("%d não é um ano bissexto.\n", ano);
    }

    return 0;
}
