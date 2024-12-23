/*
descrição: de uma quantidade de numeros,
depois leia todos esses numeros e retorne o maior
e a media deles.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.
    int vezesPraLer = 0;

    printf("Digite quantas(jozé viado) vezes é pra ler: ");
    scanf("%d", &vezesPraLer);

    int comeco = 0;
    float armazena = 0.0;
    float vetornumeros[vezesPraLer];
    for (comeco = 0; comeco < vezesPraLer; comeco++)
    {
        printf("\n %d - digite um numero: ", (comeco + 1));
        scanf("%f", &armazena);
        vetornumeros[comeco] = armazena;
    }
    printf("\n");
    for (int i = 0; i < vezesPraLer; i++)
    {
        printf(" %.2f ", vetornumeros[i]);
    }

    printf("\n");
    // media do joze viado.
    float media = 0.0;
    for (int i = 0; i < vezesPraLer; i++)
    {
        media = media + vetornumeros[i];
    }
    media = media / vezesPraLer;
    printf("\n a media disso é :  %.2f", media);

    printf("\n");
    float maiorNumero = vetornumeros[0];
    for (int i = 0; i < vezesPraLer; i++)
    {
        if (maiorNumero <= vetornumeros[i])
        {
            maiorNumero = vetornumeros[i];
        }
    }
    printf("\n Maior numero: %f", maiorNumero);

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}