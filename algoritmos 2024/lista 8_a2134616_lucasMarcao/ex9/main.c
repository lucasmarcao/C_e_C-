#include <stdio.h>

struct employee
{
    char name[50];
    float salary;
    int type; // 0 - Developer, 1 - Designer, 2 - Manager, 3 - Support
};

typedef struct employee Employee;

/*
 * Função para calcular e imprimir o total dos salários, a média dos salários
 * e as médias dos salários por tipo de empregado.
 * Entrada de Dados:
 *   - n: tamanho do vetor de empregados
 *   - v: vetor de empregados
 */
void income_report(int n, Employee v[n])
{
    // Entrada de Dados: Nenhuma, os dados já foram fornecidos como parâmetro

    // Processamento de Dados:
    float total_salary = 0.0;
    float total_salary_by_type[4] = {0.0}; // Inicializa todas as médias dos salários por tipo como zero
    int count_by_type[4] = {0};            // Contador para calcular quantos empregados de cada tipo existem

    for (int i = 0; i < n; i++)
    {
        total_salary += v[i].salary;
        total_salary_by_type[v[i].type] += v[i].salary;
        count_by_type[v[i].type]++;
    }

    float average_salary = total_salary / n;

    // Saída de Dados:
    printf("Total dos salários: %.2f\n", total_salary);
    printf("Média dos salários: %.2f\n", average_salary);
    printf("Médias dos salários por tipo de empregado:\n");
    printf("  Developer: %.2f\n", count_by_type[0] > 0 ? total_salary_by_type[0] / count_by_type[0] : 0);
    printf("  Designer: %.2f\n", count_by_type[1] > 0 ? total_salary_by_type[1] / count_by_type[1] : 0);
    printf("  Manager: %.2f\n", count_by_type[2] > 0 ? total_salary_by_type[2] / count_by_type[2] : 0);
    printf("  Support: %.2f\n", count_by_type[3] > 0 ? total_salary_by_type[3] / count_by_type[3] : 0);
}

int main()
{
    // Exemplo de uso da função income_report
    Employee v[] = {
        {"John Doe", 5000.0, 0},
        {"Jane Smith", 6000.0, 1},
        {"Alice Johnson", 7000.0, 2},
        {"Bob Brown", 5500.0, 3},
        {"Charlie Davis", 6500.0, 0}};
    int n = sizeof(v) / sizeof(v[0]);
    income_report(n, v);
    return 0;
}
