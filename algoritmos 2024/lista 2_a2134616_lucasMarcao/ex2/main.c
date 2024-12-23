#include <stdio.h>

void imprimir_numero_extenso(int numero)
{
    switch (numero)
    {
    case 0:
        printf("zero\n");
        break;
    case 1:
        printf("um\n");
        break;
    case 2:
        printf("dois\n");
        break;
    case 3:
        printf("três\n");
        break;
    case 4:
        printf("quatro\n");
        break;
    case 5:
        printf("cinco\n");
        break;
    case 6:
        printf("seis\n");
        break;
    case 7:
        printf("sete\n");
        break;
    case 8:
        printf("oito\n");
        break;
    case 9:
        printf("nove\n");
        break;
    default:
        printf("Erro: O número deve estar entre 0 e 9.\n");
    }
}

int main()
{
    int numero;

    printf("Digite um número de 0 a 9: ");
    scanf("%d", &numero);

    if (numero >= 0 && numero <= 9)
    {
        imprimir_numero_extenso(numero);
    }
    else
    {
        printf("Erro: O número deve estar entre 0 e 9.\n");
    }

    return 0;
}
