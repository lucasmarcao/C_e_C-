/*
Resumo da resolução:
Para resolver esse exercício, precisaremos criar uma função chamada
write_array que grava os dados de um vetor de inteiros em um arquivo
binário. A função deve aceitar três parâmetros: o caminho do arquivo
(filepath), o número de elementos do vetor (n), e o próprio vetor de
inteiros (v).

Usaremos a função fopen() para abrir o arquivo no modo binário.
Se o arquivo não existir, o modo "wb" irá criá-lo. Caso o arquivo
já exista, ele será sobrescrito.
Para gravar os dados no arquivo, utilizaremos a função fwrite(),
que escreve blocos de dados diretamente no arquivo.
A função fclose() será utilizada
para fechar o arquivo após a gravação.

*/

#include <stdio.h>
#include <stdlib.h>

// Função para gravar o conteúdo de um vetor de inteiros em um arquivo
// O modo "ab" permite adicionar dados ao final do arquivo existente
void write_array(const char *filepath, int n, const int *v)
{
    // Tenta abrir o arquivo no modo binário para adicionar dados ao final ("ab")
    FILE *file = fopen(filepath, "ab");

    // Verifica se houve erro ao abrir o arquivo
    if (file == NULL)
    {
        // Se não for possível abrir ou criar o arquivo, exibe uma mensagem de erro e retorna
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Escreve o conteúdo do vetor no arquivo. O tamanho do tipo de dado é especificado por sizeof(int).
    size_t elements_written = fwrite(v, sizeof(int), n, file);

    // Verifica se todos os elementos foram gravados corretamente
    if (elements_written != n)
    {
        printf("Erro ao escrever no arquivo.\n");
    }
    else
    {
        printf("Dados gravados com sucesso no arquivo %s.\n", filepath);
    }

    // Fecha o arquivo após a escrita
    fclose(file);
}

int main()
{
    // Exemplo de vetor de inteiros
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Chama a função para gravar o vetor no arquivo "dados.bin"
    write_array("dados.bin", 10, v);

    // Adiciona mais dados ao final do arquivo
    int v2[] = {11, 12, 13, 999, 15};
    write_array("dados.bin", 5, v2);

    return 0;
}
