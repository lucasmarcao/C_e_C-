/*
Descrição: A função list_is_sorted percorre a lista verificando se cada elemento
é menor ou igual ao próximo. Caso algum par de elementos consecutivos seja
encontrado onde o anterior seja maior que o próximo, a função retorna false
(0), indicando que a lista não está ordenada. Caso contrário, retorna true (1).
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectorlist.h"

// Função para verificar se a lista está ordenada
int list_is_sorted(VectorList *list)
{
    // Percorre a lista e compara elementos consecutivos
    for (int i = 0; i < list->size - 1; i++)
    {
        if (list->data[i] > list->data[i + 1])
        {
            // Se algum elemento for maior que o próximo, a lista não está ordenada
            return 0;
        }
    }
    // Se nenhum par fora de ordem for encontrado, a lista está ordenada
    return 1;
}

int main()
{
    VectorList *list = new VectorList();

    // Adiciona elementos à lista
    list->push_back(1);
    list->push_back(55);
    list->push_back(3);
    list->print();

    // Verifica se a lista está ordenada
    if (list_is_sorted(list))
    {
        printf("A lista está ordenada.\n");
    }
    else
    {
        printf("A lista não está ordenada.\n");
    }

    return 0;
}
