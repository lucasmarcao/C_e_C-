#include <stdio.h>

int main()
{
    char operador;
    int numero1, numero2;
    float resultado;

    // Solicita ao usuário que insira o operador e os números
    printf("[ CALCULADORA SIMPLEX ]\n");
    printf("Operador (+ - * / %%): ");
    scanf(" %c", &operador);

    printf("Número01: ");
    scanf("%d", &numero1);

    printf("Número02: ");
    scanf("%d", &numero2);

    // Calcula o resultado conforme o operador inserido
    switch (operador)
    {
    case '+':
        resultado = numero1 + numero2;
        break;
    case '-':
        resultado = numero1 - numero2;
        break;
    case '*':
        resultado = numero1 * numero2;
        break;
    case '/':
        if (numero2 != 0)
        {
            resultado = (float)numero1 / numero2;
        }
        else
        {
            printf("Erro: Divisão por zero.\n");
            return 1; // Retorna 1 para indicar um erro
        }
        break;
    case '%':
        if (numero2 != 0)
        {
            resultado = numero1 % numero2;
        }
        else
        {
            printf("Erro: Divisão por zero.\n");
            return 1; // Retorna 1 para indicar um erro
        }
        break;
    default:
        printf("Erro: Operador inválido.\n");
        return 1; // Retorna 1 para indicar um erro
    }

    // Imprime a expressão e o resultado com duas casas decimais de precisão
    printf("Expressão:\n");
    printf("%d %c %d = %.2f\n", numero1, operador, numero2, resultado);

    return 0;
}
