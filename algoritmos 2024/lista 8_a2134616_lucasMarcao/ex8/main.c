#include <stdio.h>

struct employee
{
    char name[50];
    float salary;
    int type; // 0 - Developer, 1 - Designer, 2 - Manager, 3 - Support
};

typedef struct employee Employee;

/*
 * Função para imprimir os nomes dos três empregados com os maiores salários.
 * Entrada de Dados:
 *   - n: tamanho do vetor de empregados
 *   - v: vetor de empregados
 */
void print_best3(int n, Employee v[n])
{
    // Processamento de Dados:
    // Ordenando os empregados por salário em ordem decrescente
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j].salary < v[j + 1].salary)
            {
                Employee temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

    // Saída de Dados:
    // Imprimindo os nomes dos três primeiros empregados
    printf("Os 3 empregados com os maiores salários são:\n");
    for (int i = 0; i < 3 && i < n; i++)
    {
        printf("%d - %s | salario: %.2f \n", (i + 1), v[i].name, v[i].salary);
    }
}

int main()
{
    // Exemplo de uso da função print_best3
    Employee v[] = {
        {"John Doe", 5000.0, 0},
        {"Jane Smith", 6000.0, 1},
        {"Alice Johnson", 7000.0, 2},
        {"Bob Brown", 5500.0, 3},
        {"Charlie Davis", 6500.0, 0}};
    int n = sizeof(v) / sizeof(v[0]);
    print_best3(n, v);
    return 0;
}
