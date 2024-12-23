/*
descrição:
*/
#include <stdio.h>
#include <string.h> // strcat()
#include <stdlib.h> // malloc()

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.

    float maioral = 0;
    printf("1 a 0:\n");
    scanf("%f", &maioral);
    printf("maioral: %f", maioral);
    float newMaioral = maioral;
    int reservinha = maioral;
    printf("reservinha %d", reservinha);

    for (int i = reservinha; i >= 0; i--)
    {

        newMaioral--;
        if (newMaioral > 0.00)
        {
            printf("\n %.2f", newMaioral);
        }
        else
        {
            printf("\n 0");
        }
    }

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}