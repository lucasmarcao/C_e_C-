#include <stdio.h>
#include <math.h>

struct point
{
    float x;
    float y;
};

typedef struct point Point;

/*
 * Função para calcular a distância entre dois pontos 2D.
 * Parâmetros:
 *   - p1: o primeiro ponto
 *   - p2: o segundo ponto
 * Retorno:
 *   - a distância entre os dois pontos
 */
float distance(Point p1, Point p2)
{
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

/*
 * Função para calcular e imprimir a distância entre cada par de pontos consecutivos em um vetor de pontos.
 * Parâmetros:
 *   - n: o tamanho do vetor de pontos
 *   - v: o vetor de pontos
 * Observação:
 *   - A função assume que o vetor contém pelo menos dois pontos.
 */
void distance_vector(int n, Point v[])
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("Distancia entre os pontos %d e %d: %.2f\n", i + 1, i + 2, distance(v[i], v[i + 1]));
    }
}

int main()
{
    Point vetor[] = {{1.0, 2.0}, {4.0, 6.0}, {7.0, 9.0}, {10.0, 12.0}};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    distance_vector(tamanho, vetor);

    return 0;
}
