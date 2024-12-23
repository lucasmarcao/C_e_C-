#include <stdio.h>

int main()
{
    int a, b;

    // Solicita ao usuário para inserir dois números inteiros
    printf("Digite o primeiro número inteiro (a): ");
    scanf("%d", &a);
    printf("Digite o segundo número inteiro (b): ");
    scanf("%d", &b);

    // Realiza as operações de multiplicação e divisão
    int multiplicacao = a * b;
    int divisao_inteira = a / b;
    float divisao_float = (float)a / b;

    // Exibe os resultados
    printf("Multiplicação: %d\n", multiplicacao);
    printf("Divisão inteira (a dividido por b): %d\n", divisao_inteira);
    printf("Divisão float (a dividido por b): %.2f\n", divisao_float);

    return 0;
}
