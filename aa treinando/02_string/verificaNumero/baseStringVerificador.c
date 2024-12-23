#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main()
{
    char input[100];
    char *endptr;
    int number;

    printf("\n");
    printf("Digite um número: ");
    if (fgets(input, sizeof(input), stdin) != NULL)
    {
        // Remove o newline do final da string
        input[strcspn(input, "\n")] = '\0';

        // Tenta converter a string para um número
        errno = 0; // Para detectar erros de overflow/underflow
        number = strtol(input, &endptr, 10);

        // Verifica se a conversão foi bem-sucedida
        if (endptr == input)
        {
            printf("Erro: Nenhum número foi encontrado.\n");
        }
        else if (*endptr != '\0')
        {
            printf("Erro: Parte da entrada não foi um número válido.\n");
        }
        else if ((errno == ERANGE && (number == INT_MAX || number == INT_MIN)) || (errno != 0 && number == 0))
        {
            printf("Erro: Número fora do intervalo permitido.\n");
        }
        else
        {
            printf("Você digitou o número: %d\n", (number * 10));
        }
    }
    else
    {
        printf("Erro ao ler a entrada.\n");
    }
    printf("\n");

    // stdout: Exibe uma mensagem padrão
    fprintf(stdout, "Essa mensagem vai para a saída padrão (stdout).\n");

    // stderr: Exibe uma mensagem de erro
    fprintf(stderr, "Essa mensagem vai para a saída de erro padrão (stderr).\n");

    return 0;
}
