// print ordem logica tipo :
// [0,1,2,4] para -->
// [1,2,2,3,3,3,3] um 1, dois 2, quatro 3.
#include <stdio.h>

void somadorDeAeB(int a, int b)
{
    printf("%d", a + b);
}

int main()
{
    printf("\n\n");
    // espaço estrategico

    /* variable definition: */
    int a = 5;
    int b = 7;
    somadorDeAeB(a, b);

    // espaço estrategico
    printf("\n\n\a");
    return 0;
}