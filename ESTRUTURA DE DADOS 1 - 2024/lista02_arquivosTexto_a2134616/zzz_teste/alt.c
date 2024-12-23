/*
descrição: crie um vetor e mostre ele
*/
#include <stdio.h>
#include <string.h> // strcat()
#include <stdlib.h> // malloc()

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.

    // qual a diferença entre calloc e malloc?
    puts("### VETOR DINAMICO COM ããã CALLOC");
    // alocacao de um vetor dinâmico usando calloc (memória Heap)
    // todo o bloco alocado possui bits 0, isto é,
    // garante que todos os elementos alocados (do vetor) terão valor 0
    int *vh_cal = (int *)calloc(5, sizeof(int)); // todos os elementos possuem
                                                 // "lixo de memória"

    printf("&vh_cal = %p vh_cal = %p\n", &vh_cal, vh_cal);

    for (int i = 0; i < 5; i++)
    {
        vh_cal[i] = (i * 2) + 2;
        printf("&vh_cal[%d] = %p, vh_cal[%d] = %d\n", i, &vh_cal[i], i, vh_cal[i]);
    }
    puts("\n");

    printf("hentai : %i", vh_cal[2]);

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}