/*
Descrição: A função list_remove_last foi implementada para remover os últimos N elementos da lista.
A lógica consiste em diminuir o valor de size, que é o número de elementos na lista,
em até N. Se N for maior do que o número de elementos na lista, todos os elementos
serão removidos. A capacidade da lista não é alterada, apenas o tamanho (size).
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectorlist.h"

// Implementação da função para remover os últimos N elementos
void list_remove_last(VectorList *list, int n)
{
    if (n >= list->size)
    {
        list->size = 0; // Se N for maior ou igual ao tamanho atual, limpa a lista
    }
    else
    {
        list->size -= n; // Caso contrário, diminui o tamanho da lista em N
    }
}

int main()
{
    VectorList *list = new VectorList();
    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    list->push_back(4);
    list->push_back(5);
    list->print(); // Mostra a lista antes de remover os elementos

    // Chama a função para remover os últimos 3 elementos
    list_remove_last(list, 3);
    printf("Lista apos remover os ultimos 3 elementos:\n");
    list->print(); // Mostra a lista após remoção

    // Chama a função para remover mais 2 elementos, mas a lista já tem apenas 2 elementos
    list_remove_last(list, 2);
    printf("Lista apos remover os ultimos 2 elementos:\n");
    list->print(); // Mostra a lista após remoção

    // Chama a função para tentar remover mais 2 elementos, mas a lista está vazia
    list_remove_last(list, 2);
    printf("Lista apos tentar remover mais 2 elementos (lista vazia):\n");
    list->print(); // Mostra a lista após tentativa de remoção

    return 0;
}
