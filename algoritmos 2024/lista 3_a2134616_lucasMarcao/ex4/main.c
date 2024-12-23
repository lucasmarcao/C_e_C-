#include <stdio.h>

int main()
{
    int a, b;

    // Solicita ao usuário para inserir dois números inteiros
    printf("Digite o primeiro número inteiro (a): ");
    scanf("%d", &a);
    printf("Digite o segundo número inteiro (b): ");
    scanf("%d", &b);

    // Calcula o resto utilizando o operador %
    int resto_operador_modulo = a % b;

    // Calcula o resto sem utilizar o operador %
    int resto_sem_operador_modulo = a - (a / b) * b;

    // Exibe os resultados
    printf("Resto utilizando o operador %%: %d\n", resto_operador_modulo);
    printf("Resto sem utilizar o operador %%: %d\n", resto_sem_operador_modulo);

    return 0;
}
