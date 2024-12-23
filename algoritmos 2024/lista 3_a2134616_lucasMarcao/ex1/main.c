#include <stdio.h>

int main()
{
    int N;

    printf("Informe o número de linhas: ");
    scanf("%d", &N);

    for (int i = N; i >= 1; i--)
    {
        printf("Linha %d\n", i);
    }

    return 0;
}
