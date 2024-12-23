// Escreva um programa que lê um número x do terminal e
// informa (imprimr) seu valor absoluto |x|, isto é:
// a. |x| = x, se x > 0
// b. |x| = -x, se x < 0

#include <stdio.h>

float numero(float numeroPositivo)
{
    if (numeroPositivo >= 0)
    {
        return numeroPositivo;
    }
    else
    {
        return -numeroPositivo;
    }
}

int main(void)
{
    float numeroPositivo;
    printf("\n digite um numero positivo \n");
    scanf(" %f", &numeroPositivo);

    float numeroConvertido = numero(numeroPositivo);

    printf("\n seu numero em modulo é | %.2f | \n", numeroConvertido);

    return 0;
}