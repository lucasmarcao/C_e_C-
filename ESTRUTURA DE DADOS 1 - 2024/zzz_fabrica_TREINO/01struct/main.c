/*
descrição: criar um struct
e adcionar dados nele
*/
#include <stdio.h>
#include <string.h> // strcat()
#include <stdlib.h> // malloc()

typedef struct personagem
{
    int id;
    char nickName[80];
    double speed;
    float size;
    long xp;
} Personagem;

void saidaPersonagem(
    Personagem personagem)
{
    printf("\n id: %d .", personagem.id);
    printf("\n nickName: %s .", personagem.nickName);
    printf("\n size: %f .", personagem.speed);
    printf("\n size: %f .", personagem.size);
    printf("\n id: %d .", personagem.xp);
}

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.
    Personagem lucas;
    lucas.id = 1;
    strcpy(
        lucas.nickName,
        "Marcaozitos explosivo");
    lucas.speed = 30.78;
    lucas.size = 1.75;
    lucas.xp = 3975304;

    saidaPersonagem(lucas);

    float marcaoFloat[] = {223.98, 36.936, 9191.4953, 68};
    int tamanhoVetorMarcaoFloat = (sizeof(marcaoFloat)) / (sizeof(int));

    for (size_t index = 0; index < tamanhoVetorMarcaoFloat; index++)
    {
        printf("\n | %d vetor: %.3f", index, marcaoFloat[index]);
    }

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}