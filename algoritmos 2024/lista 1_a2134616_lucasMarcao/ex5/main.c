#include <stdio.h>

void print_mult_table(int number)
{
    int i;

    // Itera de 1 até 10 para imprimir a tabuada
    for (i = 1; i <= 10; i++)
    {
        // Imprime a multiplicação alinhada com %2d
        printf("%2d x %2d = %2d   ", number, i, number * i);

        // A cada múltiplo de 5, imprime uma nova linha
        if (i % 5 == 0)
            printf("\n");
    }
}

int main()
{
    int number;

    // Solicita ao usuário para inserir um número inteiro
    printf("Digite um número inteiro para imprimir a tabuada: ");
    scanf("%d", &number);

    // Chama a função para imprimir a tabuada do número fornecido
    print_mult_table(number);

    return 0;
}
