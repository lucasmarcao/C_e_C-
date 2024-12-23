/*
Resumo da solução:
O problema consiste em ler um arquivo binário e armazenar seus
dados em um vetor de inteiros, alocado na heap. Para isso,
primeiro precisamos abrir o arquivo e verificar se ele foi
aberto corretamente. Em seguida, calculamos o número de inteiros
que podem ser lidos com base no tamanho do arquivo. Se o arquivo
for válido, alocamos a memória necessária para armazenar os inteiros
e fazemos a leitura do conteúdo para o vetor. Caso haja algum
erro durante a abertura do arquivo, alocação de memória ou leitura,
a função deve retornar NULL. O tamanho do vetor é retornado por
meio de um parâmetro de saída. Após o uso, a memória alocada é
liberada no main.

*/

// ABRIR NO TERMINAL INTEGRADO.
//   g++ mainCPP.cpp -o mainCPP.exe
//   ./mainCPP.exe
#include <iostream> // Para entrada e saída
#include <fstream>  // Para manipulação de arquivos
#include <cstdlib>  // Para funções de alocação de memória

using namespace std;

// Função que lê os dados de um arquivo e armazena em um vetor alocado na heap
int *read_array(const char *filepath, int *n)
{
    // Tenta abrir o arquivo em modo binário
    ifstream file(filepath, ios::binary);

    // Verifica se o arquivo foi aberto corretamente
    if (!file.is_open())
    {
        cout << "Erro ao abrir o arquivo.\n";
        return NULL; // Retorna NULL caso o arquivo não possa ser aberto
    }

    // Move o ponteiro do arquivo para o final para determinar o tamanho do arquivo
    file.seekg(0, ios::end);
    long file_size = file.tellg(); // Obtém o tamanho do arquivo em bytes
    file.seekg(0, ios::beg);       // Reseta o ponteiro para o início do arquivo

    // Calcula o número de inteiros que podemos armazenar no vetor (tamanho do arquivo dividido pelo tamanho de um int)
    *n = file_size / sizeof(int);

    // Aloca a memória necessária para o vetor
    int *v = new int[*n];
    if (!v)
    {
        cout << "Erro ao alocar memória.\n";
        file.close(); // Fecha o arquivo antes de retornar
        return NULL;
    }

    // Lê os dados do arquivo para o vetor
    file.read(reinterpret_cast<char *>(v), file_size);

    // Verifica se todos os dados foram lidos corretamente
    if (file.gcount() != file_size)
    {
        cout << "Erro ao ler os dados do arquivo.\n";
        delete[] v; // Libera a memória em caso de erro
        file.close();
        return NULL;
    }

    // Fecha o arquivo após a leitura
    file.close();

    // Retorna o ponteiro para o vetor de inteiros alocado na heap
    return v;
}

// Função para imprimir o conteúdo do vetor
void print_array(int n, int *v)
{
    if (v == NULL)
    {
        cout << "Vetor vazio.\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n; // Variável para armazenar o tamanho do vetor

    // Lê o conteúdo do arquivo "dados.bin" para o vetor 'v'
    int *v = read_array("dados.bin", &n);

    // Se a leitura foi bem-sucedida, imprime os dados
    if (v != NULL)
    {
        print_array(n, v);
        delete[] v; // Libera a memória alocada após o uso
    }

    return 0;
}
