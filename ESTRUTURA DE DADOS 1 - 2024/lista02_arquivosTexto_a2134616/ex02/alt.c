/*
descrição:
Função que verifica se um arquivo existe. Caso não exista, tenta criá-lo.
Retorna 1 se o arquivo existir ou for criado com sucesso, e 0 caso contrário.
*/

#include <stdio.h>
#include <string.h>   // strcat()
#include <stdlib.h>   // malloc()
#include <sys/stat.h> // struct stat
#include <fcntl.h>    // open()
#include <unistd.h>   // close()

int check_or_create(const char *filepath)
{
    struct stat buffer;

    // Verifica se o arquivo existe
    if (stat(filepath, &buffer) == 0)
    {
        return 1; // Arquivo existe
    }

    // Tenta criar o arquivo
    int file = open(filepath, O_CREAT | O_WRONLY, 0644);
    if (file != -1)
    {
        close(file);
        return 1; // Arquivo criado com sucesso
    }

    return 0; // Falha ao criar o arquivo
}

int main()
{
    printf("\n\n");
    // espaço estrategico.

    // Inicio do programa.

    const char *caminho = "C:\\Users\\Usuario\\Documents\\trulis24.exe";
    int resultado = check_or_create(caminho);
    if (resultado)
    {
        printf("Arquivo existe ou foi criado com sucesso.\n");
    }
    else
    {
        printf("Erro ao verificar ou criar o arquivo.\n");
    }

    // espaço estrategico.
    printf("\n\n\a");
    return 0;
}
