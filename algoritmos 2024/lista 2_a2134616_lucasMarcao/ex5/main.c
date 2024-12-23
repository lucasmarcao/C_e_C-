#include <stdio.h>

int main()
{
    float n1, n2, n3, media;

    // Solicita ao usuário que insira as três notas
    printf("Digite a primeira nota (de 0 a 10): ");
    scanf("%f", &n1);

    printf("Digite a segunda nota (de 0 a 10): ");
    scanf("%f", &n2);

    printf("Digite a terceira nota (de 0 a 10): ");
    scanf("%f", &n3);

    // Verifica se as notas estão dentro do intervalo válido
    if (n1 < 0 || n1 > 10 || n2 < 0 || n2 > 10 || n3 < 0 || n3 > 10)
    {
        printf("Erro: As notas devem estar no intervalo de 0 a 10.\n");
        return 1; // Retorna 1 para indicar um erro
    }

    // Calcula a média aritmética das três notas
    media = (n1 + n2 + n3) / 3.0;

    // Determina o conceito do aluno com base na média
    char conceito;
    if (media >= 8.5 && media <= 10)
    {
        conceito = 'A';
    }
    else if (media >= 7.0 && media < 8.5)
    {
        conceito = 'B';
    }
    else if (media >= 5.5 && media < 7.0)
    {
        conceito = 'C';
    }
    else
    {
        conceito = 'F';
    }

    // Imprime a média e o conceito obtido pelo aluno
    printf("Média: %.2f\n", media);
    printf("Conceito: %c\n", conceito);

    return 0;
}
