/*

descrição: faça isso

piramede(int linhas){}

    *
   ***
  *****
 *******
*********

*/

#include <stdio.h>

void piramede(int linhas)
{
    int linhaCont = 0;
    int area = linhas * ((linhas * 2) - 1);
    int colunas = ((linhas * 2) - 1);
    // colunas/2 (+ e menos linhaCont)

    /*

se eu sou o maior em
1234567| +1
   *   | 1
  ***  | 2
 ***** | 3
*******| 4

na primeira vez: retorne o : 1-      [4]
na segunda vez: retorne o : 2 -    [3,4,5]
na terceira vez: retorne o : 3 - [2,3,4,5,6]
na quarta vez: retorne o : 3 - [1,2,3,4,5,6,7]
    */

    printf("area : %d", area);
    printf("  colunas : %d", colunas);
    printf("\n");
    if (linhas > 0)
    {
        for (size_t i = 0; i < area; i++)
        {
            if (linhas == 1)
            {
                printf("\n * ");
                break;
            }
            if ((i % colunas) == 0)
            {
                linhaCont = linhaCont + 1;
                printf("\n");
            }
            if (
                ((i % colunas) <= ((linhas - linhaCont) - 1) || (i % colunas) >= ((linhas + linhaCont) - 1)) && linhaCont != (linhas))
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
    }
    else
    {
        printf("|   |");
    }

    printf("\n\nlinhaCont = %d\n", linhaCont);
}

int main(void)
{
    int acabou = 0;
    int entrada = 0;
    while (acabou == 0)
    {
        printf("\nQuantas linhas vai ter sua piramede?\n");
        scanf("%d", &entrada);
        piramede(entrada);
    }
    return 0;
}