#include <stdio.h>
#include <string.h>

// Função para inverter uma palavra
void inverterPalavra(char palavra[])
{
    int comprimento = strlen(palavra);
    for (int i = 0; i < comprimento / 2; ++i)
    {
        char temp = palavra[i];
        palavra[i] = palavra[comprimento - 1 - i];
        palavra[comprimento - 1 - i] = temp;
    }
}

int main()
{
    char palavra[] = "macaquito";

    printf("Palavra original: %s\n", palavra);
    inverterPalavra(palavra);
    printf("Palavra invertida: %s\n", palavra);

    return 0;
}
