#include <stdio.h>
#include <string.h>

int string_to_int(const char number_str[])
{
    int length = strlen(number_str);
    int result = 0;
    int base = 1; // Valor inicial da base

    // Percorre a string da direita para a esquerda
    for (int i = length - 1; i >= 0; i--)
    {
        // Converte o caractere para o valor numérico
        int digit = number_str[i] - '0';
        // Multiplica o dígito pelo valor da base e soma ao resultado
        result += digit * base;
        // Atualiza o valor da base (multiplica por 10)
        base *= 10;
    }

    return result;
}

int main()
{
    int n = string_to_int("1024");
    printf("%d\n", n); // Saída: 1024
    return 0;
}
