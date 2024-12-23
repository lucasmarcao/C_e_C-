#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int file_exists(const char *filepath)
{
    FILE *file = fopen(filepath, "r"); // Tenta abrir o arquivo no modo de leitura
    if (file)
    {
        fclose(file); // Fecha o arquivo, já que ele foi aberto com sucesso
        return 1;     // O arquivo existe
    }
    return 0; // O arquivo não existe
}

int main()
{
    const char *path = "C:\\Users\\Usuario\\Documents\\xesque2.exe";
    int res = file_exists(path);
    // Documentos

    if (res == 1)
    {
        printf("O arquivo existe.\n");
    }
    else
    {
        printf("O arquivo não existe.\n");
    }

    return 0;
}
