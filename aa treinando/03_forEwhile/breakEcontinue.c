/*
descrição: usa os comandos break e continue
 pra criar algo daora.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.
    int comeco = 0;
    int fim = 100;

    for (comeco; comeco <= fim; comeco++)
    {
        if (comeco % 2 == 0)
        {
            printf(" %d ", comeco);
        }

        if (comeco % 2 == 1)
        {
            continue;
            printf(" %d ", comeco);
        }

        if (comeco == 80)
        {
            break;
        }
    }

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}