#include <stdio.h>
#include <math.h>

struct point
{
    float x;
    float y;
};

typedef struct point Point;

struct distance_info
{
    float distance;
    int index1;
    int index2;
};

typedef struct distance_info DistanceInfo;

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
 * Função para encontrar os dois pontos mais próximos em um vetor de pontos.
 * Parâmetros:
 *   - n: o tamanho do vetor de pontos
 *   - v: o vetor de pontos
 * Observação:
 *   - A função imprime os dois pontos mais próximos juntamente com a distância entre eles.
 */
void nearest_points(int n, Point v[])
{
    DistanceInfo closest_pair = {INFINITY, -1, -1}; // Inicializa a estrutura com uma distância infinita

    // Calcula as distâncias entre todos os pares de pontos e encontra os dois mais próximos
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float dist = distance(v[i], v[j]);
            if (dist < closest_pair.distance && dist > 0)
            {
                closest_pair.distance = dist;
                closest_pair.index1 = i;
                closest_pair.index2 = j;
            }
        }
    }

    // Imprime os dois pontos mais próximos e a distância entre eles
    printf("Os dois pontos mais próximos são:\n");
    printf("Ponto 1: (%.2f, %.2f)\n", v[closest_pair.index1].x, v[closest_pair.index1].y);
    printf("Ponto 2: (%.2f, %.2f)\n", v[closest_pair.index2].x, v[closest_pair.index2].y);
    printf("Distância entre eles: %.2f\n", closest_pair.distance);
}

int main()
{
    // Exemplo de uso da função nearest_points
    int tamanho = 5;
    Point vetor[] = {{1.0, 2.0}, {4.0, 6.0}, {7.0, 9.0}, {10.0, 12.0}, {5.0, 5.0}};

    nearest_points(tamanho, vetor);

    return 0;
}
