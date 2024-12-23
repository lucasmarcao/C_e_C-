/*
Descrição: A função list_from_vector cria uma lista sequencial a partir de um vetor passado
como parâmetro. A capacidade da lista será o dobro do tamanho do vetor. Para isso, é
necessário alocar memória para a estrutura da lista, copiando os elementos do vetor
para o campo `data` da lista e ajustando seu tamanho e capacidade. A função retorna a lista
criada, que estará pronta para ser manipulada.
*/

#include "vectorlist.h"
#include <stdio.h>
#include <stdlib.h>

// Função para criar uma lista a partir de um vetor
VectorList *list_from_vector(int n, int *vet)
{
    // Cria uma nova lista com capacidade 2 vezes maior que o vetor
    VectorList *newList = new VectorList();
    newList->capacity = 2 * n; // Capacidade é o dobro do tamanho do vetor
    newList->size = n;         // O tamanho inicial é igual ao do vetor

    // Aloca memória para o vetor de dados da lista
    newList->data = new int[newList->capacity];

    // Copia os elementos do vetor para a lista
    for (int i = 0; i < n; i++)
    {
        newList->data[i] = vet[i];
    }

    // Retorna a lista criada
    return newList;
}

int main()
{
    // Exemplo de uso da função list_from_vector

    // Um vetor de exemplo
    int vet[] = {1, 2, 3, 4, 5, 77, 11};
    int n = sizeof(vet) / sizeof(vet[0]);

    // Cria uma lista a partir do vetor
    VectorList *list = list_from_vector(n, vet);

    // Imprime a lista criada
    list->print();

    return 0;
}

/*
Complexidade:
Tempo: A função list_from_vector possui complexidade O(n), onde n é o
número de elementos no vetor, pois ela copia todos os elementos para a lista.
Espaço: A complexidade de espaço é O(n), já que a função aloca
um vetor de tamanho 2 * n para armazenar os dados da lista.
Este código oferece uma maneira eficiente de criar uma
lista sequencial a partir de um vetor, com capacidade
dinâmica ajustada de acordo com o tamanho do vetor original.
*/