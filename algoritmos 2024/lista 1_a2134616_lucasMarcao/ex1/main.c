#include <stdio.h>

int main()
{
    int a, b;

    // Solicita ao usuário para inserir dois números inteiros
    printf("Digite o primeiro número inteiro (a): ");
    scanf("%d", &a);
    printf("Digite o segundo número inteiro (b): ");
    scanf("%d", &b);

    // Realiza as operações de adição e subtração
    int adicao = a + b;
    int subtracao = a - b;

    // Exibe os resultados
    printf("Adição: %d\n", adicao);
    printf("Subtração (a - b): %d\n", subtracao);

    return 0;
}
