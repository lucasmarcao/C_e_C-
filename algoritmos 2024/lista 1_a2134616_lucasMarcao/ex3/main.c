#include <stdio.h>

#define PI 3.141593

int main()
{
    float raio;

    // Solicita ao usuário para inserir o raio do círculo
    printf("Digite o raio do círculo: ");
    scanf("%f", &raio);

    // Calcula o diâmetro, circunferência e área do círculo
    float diametro = 2 * raio;
    float circunferencia = 2 * PI * raio;
    float area = PI * raio * raio;

    // Exibe os resultados
    printf("Diâmetro: %.2f\n", diametro);
    printf("Circunferência: %.2f\n", circunferencia);
    printf("Área do círculo: %.2f\n", area);

    return 0;
}
