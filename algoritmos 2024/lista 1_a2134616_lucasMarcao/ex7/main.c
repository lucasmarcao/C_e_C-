#include <stdio.h>

void print_days(int days)
{
    // Calcula a quantidade de anos, semanas e dias
    int anos = days / 365;
    int semanas = (days % 365) / 7;
    int dias_restantes = (days % 365) % 7;

    // Imprime o resultado
    printf("Dias: %d = %d ano(s), %d semana(s) e %d dia(s)\n", days, anos, semanas, dias_restantes);
}

int main()
{
    int days;

    // Solicita ao usuário para inserir o número de dias
    printf("Digite o número de dias: ");
    scanf("%d", &days);

    // Chama a função para imprimir a conversão
    print_days(days);

    return 0;
}
