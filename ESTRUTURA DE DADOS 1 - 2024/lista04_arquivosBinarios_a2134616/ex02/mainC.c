#include <stdio.h>
#include <stdlib.h>

// Função para ler o conteúdo de um arquivo e armazenar os dados em um vetor alocado na heap
int *read_array(const char *filepath, int *n)
{
    // Abre o arquivo em modo binário para leitura
    FILE *file = fopen(filepath, "rb");

    // Verifica se o arquivo foi aberto com sucesso
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return NULL; // Retorna NULL caso o arquivo não possa ser aberto
    }

    // Move o ponteiro do arquivo para o final para determinar o tamanho do arquivo
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file); // Obtém o tamanho do arquivo em bytes
    fseek(file, 0, SEEK_SET);     // Reseta o ponteiro do arquivo para o início

    // Calcula o número de inteiros que podem ser lidos (tamanho do arquivo dividido pelo tamanho de um int)
    *n = file_size / sizeof(int);

    // Aloca memória para o vetor de inteiros com o tamanho calculado
    int *v = (int *)malloc(file_size);

    // Verifica se a alocação de memória foi bem-sucedida
    if (v == NULL)
    {
        printf("Erro ao alocar memória.\n");
        fclose(file); // Fecha o arquivo antes de retornar
        return NULL;
    }

    // Lê os dados do arquivo para o vetor
    size_t elements_read = fread(v, sizeof(int), *n, file);

    // Verifica se todos os elementos foram lidos corretamente
    if (elements_read != *n)
    {
        printf("Erro ao ler os dados do arquivo.\n");
        free(v); // Libera a memória alocada em caso de erro
        fclose(file);
        return NULL;
    }

    // Fecha o arquivo após a leitura
    fclose(file);

    // Retorna o ponteiro para o vetor de inteiros alocado na heap
    return v;
}

// Função para imprimir o conteúdo do vetor
void print_array(int n, int *v)
{
    if (v == NULL)
    {
        printf("Vetor vazio.\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main()
{
    int n; // Variável para armazenar o tamanho do vetor
    // Chama a função para ler os dados do arquivo "dados.bin"
    int *v = read_array("dados.bin", &n);

    // Se a leitura foi bem-sucedida, imprime os dados
    if (v != NULL)
    {
        print_array(n, v);
        free(v); // Libera a memória alocada após o uso
    }

    return 0;
}
