/*
Descrição: A função `list_copy` cria uma nova lista sequencial que contém os mesmos valores da
lista original. Para isso, a função aloca memória para uma nova lista com a mesma capacidade
e tamanho da lista original. Depois, ela copia os elementos de `list->data` para o novo vetor
de dados da nova lista. Por fim, a nova lista é retornada, preservando os valores da lista original.
*/

#include "vectorlist.h"
#include <stdio.h>
#include <stdlib.h>

// Função para criar uma cópia da lista
VectorList *list_copy(VectorList *list)
{
    // Cria uma nova lista
    VectorList *newList = new VectorList();

    // A nova lista tem o mesmo tamanho e capacidade da lista original
    newList->size = list->size;
    newList->capacity = list->capacity;

    // Aloca memória para o vetor de dados da nova lista
    newList->data = new int[newList->capacity];

    // Copia os elementos da lista original para a nova lista
    for (int i = 0; i < list->size; i++)
    {
        newList->data[i] = list->data[i];
    }

    // Retorna a nova lista
    return newList;
}

int main()
{
    // Exemplo de uso da função list_copy

    // Cria uma lista de exemplo
    VectorList *list = new VectorList();
    list->push_back(1);
    list->push_back(2);
    list->push_back(3);

    // Cria uma cópia da lista original
    VectorList *copy = list_copy(list);

    // Imprime a lista original
    printf("Lista original: ");
    list->print();

    // Imprime a cópia da lista
    printf("Cópia da lista: ");
    copy->print();

    return 0;
}
