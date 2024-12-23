// 1. Definir o struct
#include <iostream>

// não ficar escrevendo "std" toda hora.
using namespace std;

// não usa acento por enquanto.
struct ListaSequencial
{
    int elementos[100]; // Vetor que armazena até 100 elementos
    int tamanho;        // Armazena o número de elementos na lista
};

// 2. Inicializar a lista
void inicializar(ListaSequencial &lista)
{
    lista.tamanho = 0; // Começa com a lista vazia
}

// 3. Adicionar um elemento à lista
void adicionar(ListaSequencial &lista, int valor)
{
    if (lista.tamanho < 100)
    {                                           // Verifica se há espaço para adicionar
        lista.elementos[lista.tamanho] = valor; // Adiciona o valor
        lista.tamanho++;                        // Aumenta o tamanho da lista
    }
    else
    {
        cout << "Lista cheia!" << endl;
    }
}

// 4. Imprimir a lista
void imprimir(ListaSequencial &lista)
{
    if (lista.tamanho == 0)
    {
        cout << "A lista esta vazia!" << endl;
    }
    else
    {
        for (int i = 0; i < lista.tamanho; i++)
        {
            cout << lista.elementos[i] << " "; // Imprime cada elemento
        }
        cout << endl;
    }
}

// 5. Remover um elemento da lista
void remover(ListaSequencial &lista, int valor)
{
    int i = 0;
    while (i < lista.tamanho && lista.elementos[i] != valor)
    {
        i++; // Encontra o valor a ser removido
    }

    if (i == lista.tamanho)
    {
        cout << "Valor nao encontrado!" << endl;
    }
    else
    {
        // Desloca todos os elementos à direita para a esquerda
        for (int j = i; j < lista.tamanho - 1; j++)
        {
            lista.elementos[j] = lista.elementos[j + 1];
        }
        lista.tamanho--; // Decrementa o tamanho da lista
    }
}

// 6. Função main para testar a lista
int main()
{
    cout << "\n\n"; // espaço estratégico.
    // Início do programa.

    ListaSequencial lista;

    // Inicializa a lista
    inicializar(lista);

    // Adiciona elementos à lista
    adicionar(lista, 10);
    adicionar(lista, 20);
    adicionar(lista, 30);
    adicionar(lista, 40);

    // Imprime a lista
    cout << "Lista apos adicao de elementos: ->  ";
    imprimir(lista);

    // Remove um elemento
    remover(lista, 20);
    cout << "Lista apos remocao de 20: ->  ";
    imprimir(lista);

    // Lista após adição de elementos : 10 20 30 40
    // Lista após remoção de 20 : 10 30 40

    // Espaço estratégico
    cout << "\n\n\a";
    // Imprime uma nova linha e o alerta sonoro (beep)

    return 0;
}
