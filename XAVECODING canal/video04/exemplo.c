/*
descrição: descrição.
*/
#include <stdio.h>  // scanf("%d", &inteiro );
#include <string.h> // strcat( "ban" , "ana." , 3);
#include <stdlib.h> // malloc(tamVetor*sizeof(int));
// control + PgUp muda a guia VScode

int main()
{
    printf("\n");
    printf("\n");
    //  espaço estrategico.

    // Inicio do programa.
    int a = 10;
    int *p1 = NULL;
    int *p2;
    // printf("sizeof(%d)", sizeof(int *));

    printf("&a = %p | a = %d \n", &a, a);
    printf("&p1 = %p | p1 = %p \n", &p1, p1);
    printf("&p2 = %p | p2 = %p \n", &p2, p2);

    p1 = &a;
    p2 = p1;
    *p2 = 4;

    printf("\n\n&a = %p | a = %d \n", &a, a);
    printf("&p1 = %p | p1 = %p | *p1 = %d \n", &p1, p1, *p1);
    printf("&p2 = %p | p2 = %p | *p2 = %d  \n", &p2, p2, *p2);
    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}
