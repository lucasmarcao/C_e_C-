#include <stdio.h>
#include <math.h>

void distances(int n, int points[])
{
    if (n % 2 != 0)
    {
        printf("Erro: número ímpar de coordenadas. Deve haver um número par de coordenadas (X, Y).\n");
        return;
    }

    int num_points = n / 2;
    for (int i = 0; i < num_points - 1; i++)
    {
        int x1 = points[2 * i];
        int y1 = points[2 * i + 1];
        int x2 = points[2 * (i + 1)];
        int y2 = points[2 * (i + 1) + 1];

        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        printf("Distância entre ponto %d e ponto %d: %.2lf\n", i + 1, i + 2, distance);
    }
}

int main()
{
    int points[] = {0, 0, 3, 4, 6, 8};
    int n = sizeof(points) / sizeof(points[0]);

    distances(n, points);

    return 0;
}
