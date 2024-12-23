#include <stdio.h>

void imprimir_por_extenso(int numero)
{
    // Arrays com as palavras correspondentes aos dígitos
    const char *unidades[10] = {"zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    const char *dezenas[10] = {"", "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
    const char *especiais[10] = {"dez", "onze", "doze", "treze", "catorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};

    // Verifica se o número é negativo e imprime "menos" caso seja
    if (numero < 0)
    {
        printf("menos ");
        numero = -numero; // Torna o número positivo para facilitar a manipulação
    }

    // Extrai os dígitos do número
    int milhar = numero / 1000;
    int centena = (numero / 100) % 10;
    int dezena = (numero / 10) % 10;
    int unidade = numero % 10;

    // Imprime o número por extenso
    if (milhar != 0)
    {
        printf("%s mil ", unidades[milhar]);
    }
    if (centena != 0)
    {
        printf("%scento e ", unidades[centena]);
    }
    if (dezena == 1)
    {
        printf("%s ", especiais[unidade]);
    }
    else if (dezena > 1)
    {
        printf("%s e %s ", dezenas[dezena], unidades[unidade]);
    }
    else if (unidade != 0)
    {
        printf("%s ", unidades[unidade]);
    }

    printf("\n");
}

int main()
{
    int numero;

    // Solicita ao usuário que insira um número inteiro de até 4 dígitos
    printf("Digite um número inteiro de até 4 dígitos: ");
    scanf("%d", &numero);

    // Verifica se o número tem até 4 dígitos
    if (numero < -9999 || numero > 9999)
    {
        printf("Erro: O número deve ter até 4 dígitos.\n");
        return 1; // Retorna 1 para indicar um erro
    }

    // Imprime o número por extenso
    printf("O número por extenso é: ");
    imprimir_por_extenso(numero);

    return 0;
}
