#include <stdio.h>

int main()
{
    int n, soma = 0;

    printf("Informe o número: ");
    scanf("%d", &n);

    // Calculando a soma dos n primeiros números ímpares
    for (int i = 1, impar = 1; i <= n; i++, impar += 2)
    {
        soma += impar;
        printf("%d", impar);
        if (i < n)
        {
            printf(" + ");
        }
    }

    // Imprimindo a soma e calculando o quadrado
    printf(" = %d\n", soma * soma);

    return 0;
}
