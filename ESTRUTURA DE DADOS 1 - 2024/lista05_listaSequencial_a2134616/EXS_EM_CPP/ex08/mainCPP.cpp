/*
Descrição: A função list_add recebe um vetor de inteiros e tenta adicionar seus
elementos à lista. A função percorre o vetor e, para cada elemento, tenta
adicioná-lo ao final da lista utilizando o método push_back. Se a capacidade
da lista for atingida, a adição é interrompida e elementos restantes são ignorados.
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectorlist.h"

// Função para adicionar elementos em lote na lista
void list_add(VectorList *list, int n, int *vet)
{
    // Itera sobre o vetor de inteiros recebido
    for (int i = 0; i < n; i++)
    {
        // Tenta adicionar o elemento ao final da lista
        if (list->size < list->capacity)
        {
            list->push_back(vet[i]);
        }
        else
        {
            // Se a capacidade for atingida, interrompe o processo
            break;
        }
    }
}

int main()
{
    VectorList *list = new VectorList();

    // Adiciona alguns elementos manualmente
    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    list->print();

    // Vetor de elementos para adicionar em lote
    int vet[] = {4, 5, 6, 7, 8};
    int n = sizeof(vet) / sizeof(vet[0]); // Tamanho do vetor

    // Adiciona os elementos do vetor à lista
    list_add(list, n, vet);
    list->print(); // Imprime a lista após adicionar os elementos

    return 0;
}
