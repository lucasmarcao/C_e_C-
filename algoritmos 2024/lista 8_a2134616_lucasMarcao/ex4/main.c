#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Para usar a função time() como semente para a função rand()

struct point
{
    float x;
    float y;
};

typedef struct point Point;

/*
 * Função para inicializar um vetor de pontos com valores aleatórios dentro do intervalo [-50, 50].
 * Parâmetros:
 *   - n: o tamanho do vetor de pontos
 *   - v: o vetor de pontos a ser inicializado
 * Observação:
 *   - A função utiliza a função rand() para gerar os valores aleatórios.
 */
void random_points(int n, Point v[])
{
    // Define a semente para a função rand() com base no tempo atual
    srand(time(NULL));

    // Loop para inicializar cada ponto do vetor
    for (int i = 0; i < n; i++)
    {
        // Gera valores aleatórios para as coordenadas x e y dentro do intervalo [-50, 50]
        v[i].x = (float)rand() / RAND_MAX * 100 - 50; // Gera valores entre -50 e 50
        v[i].y = (float)rand() / RAND_MAX * 100 - 50; // Gera valores entre -50 e 50
    }
}

int main()
{
    // Exemplo de uso da função random_points
    int tamanho = 5;
    Point vetor[tamanho];

    random_points(tamanho, vetor);

    // Imprime os pontos inicializados
    printf("Pontos inicializados:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("Ponto %d: (%.2f, %.2f)\n", i + 1, vetor[i].x, vetor[i].y);
    }

    return 0;
}
