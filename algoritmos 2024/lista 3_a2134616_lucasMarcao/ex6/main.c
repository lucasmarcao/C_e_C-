#include <stdio.h>

void print_float(float number)
{
    // a. Imprime o número com 2 casas de precisão
    printf("a. Número com 2 casas de precisão: %.2f\n", number);

    // b. Separa a parte inteira e a parte decimal
    int parte_inteira = (int)number;
    float parte_decimal = number - parte_inteira;
    printf("b. Parte inteira: %d\n", parte_inteira);
    printf("   Parte decimal: %.6f\n", parte_decimal); // Imprime até 6 casas decimais

    // c. Representação em notação científica (mantissa/expoente)
    printf("c. Notação científica: %e\n", number);
}

int main()
{
    float number;

    // Solicita ao usuário para inserir um número float
    printf("Digite um número float: ");
    scanf("%f", &number);

    // Chama a função para imprimir as informações do número fornecido
    print_float(number);

    return 0;
}
