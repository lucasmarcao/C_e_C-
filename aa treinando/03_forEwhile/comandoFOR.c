/*
descrição: faça uma string que é soletrada.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void soletra_palavra(char palavra[])
{
    int inicio = 0;
    int tamanhoDaPlavra = (strlen(palavra) - 1);
    // em vez de virgula( , ) é ponto e virgula( ; )
    printf("\n");
    for (tamanhoDaPlavra; tamanhoDaPlavra >= inicio; tamanhoDaPlavra--)
    {
        printf("%c", palavra[tamanhoDaPlavra]);
    }
}

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.
    char palavra[50] = "";
    printf("Digite uma unica palavra: ");
    // "%50[^\n]" é um macete pra imprimir mais de
    // uma palavra nos tipos char, coisa que não é
    // possivel de fazer apenas com "%s" no scanf()
    scanf("%50[^\n]", palavra);
    // ainda tem ponto fraco, não consigo
    // digitar "ç" ou "ã" nesse "%50[^\n]".

    soletra_palavra(palavra);

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}