/*
descrição: crie tres variaveis e aprenda ponteiros.
*/
#include <stdio.h>
// scanf("%d" , inteiro); - printf("%s" , valor);
#include <string.h> // strcat();
#include <stdlib.h> // calloc(10, sizeof(int));

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.
    int a = 10;
    int b, c;

    printf("&a = %p | a = %d \n", &a, a);
    printf("&b = %p | b = %d \n", &b, b);
    printf("&c = %p | c = %d \n", &c, c);

    b = 20;
    c = a + b;

    printf("&a = %p | a = %d \n", &a, a);
    printf("&b = %p | b = %d \n", &b, b);
    printf("&c = %p | c = %d \n", &c, c);

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}