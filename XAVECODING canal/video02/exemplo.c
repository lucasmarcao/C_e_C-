/*
descrição: XXXxxxxXXX
*/
#include <stdio.h>  // scanf("%d", &inteiro );
#include <string.h> // strcat( "ban" , "ana." , 3);
#include <stdlib.h> // malloc(tamVetor*sizeof(int));

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.

    char frase[] = "suco de uva"; // frase
    int tam = strlen(frase);      // len [11]
    printf("%d \n", tam);         // mostra o tamanho da String.
    for (int i = 0; i < tam; i++)
    {
        printf("%c", frase[i]); // printa a frase
    }

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}
