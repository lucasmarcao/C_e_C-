/*
descrição: faça um programa
que não pare até o usuario digitar 0.
enquanto isso retorne a soma de todos
os numeros que o user digitou.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.
    int verificaWhile = 1;
    // o contador não pode ficar dentro do While,
    // já que não deve repetir seu valor.
    float contadorDaSoma = 0.0;

    while (verificaWhile != 0)
    {
        float soma = 0.0;
        printf("\n digite um numero: ");
        scanf("%f", &soma);
        contadorDaSoma = contadorDaSoma + soma;
        printf("\n contador atual %.2f \n", contadorDaSoma);

        if (soma == 0.0)
        {
            verificaWhile = 0;
            printf("\n Fim do programa.");
        }
    }

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}