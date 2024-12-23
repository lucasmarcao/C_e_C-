#include <stdio.h>

int main()
{
    int numero, digito;

    // Solicita ao usuário que insira um número de 5 dígitos
    printf("Digite um número de 5 dígitos: ");
    scanf("%d", &numero);

    // Verifica se o número tem 5 dígitos
    if (numero < 10000 || numero > 99999)
    {
        printf("Erro: O número deve ter 5 dígitos.\n");
        return 1; // Retorna 1 para indicar um erro
    }

    // Imprime cada dígito separado
    printf("Os dígitos separados do número são: ");
    while (numero > 0)
    {
        // Calcula o último dígito
        digito = numero % 10;
        // Imprime o último dígito
        printf("%d ", digito);
        // Remove o último dígito atualizando o número
        numero = numero / 10;
    }

    printf("\n");

    return 0;
}
