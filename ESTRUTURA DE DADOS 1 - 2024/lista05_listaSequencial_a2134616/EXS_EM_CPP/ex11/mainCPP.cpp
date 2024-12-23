/*
Descrição: A função list_equal compara duas listas. Primeiramente, verifica se as listas
têm o mesmo tamanho. Se o tamanho for diferente, retorna false imediatamente. Se o tamanho
for igual, percorre ambas as listas, comparando elemento por elemento. Se algum elemento
for diferente, retorna false. Caso todas as comparações sejam iguais, retorna true.
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectorlist.h"

// Função para verificar se duas listas são iguais
int list_equal(VectorList *list1, VectorList *list2)
{
    // Verifica se o tamanho das listas é diferente
    if (list1->size != list2->size)
    {
        return 0; // Retorna false (0) se os tamanhos são diferentes
    }

    // Percorre ambas as listas e compara os elementos
    for (int i = 0; i < list1->size; i++)
    {
        if (list1->data[i] != list2->data[i])
        {
            return 0; // Retorna false (0) se algum elemento for diferente
        }
    }

    // Se todas as comparações forem iguais, retorna true (1)
    return 1;
}

int main()
{
    // Cria e inicializa duas listas
    VectorList *list1 = new VectorList();
    list1->push_back(1);
    list1->push_back(2);
    list1->push_back(3);

    VectorList *list2 = new VectorList();
    list2->push_back(1);
    list2->push_back(2);
    list2->push_back(3);

    // Imprime as listas (opcional)
    list1->print();
    list2->print();

    // Verifica se as listas são iguais
    if (list_equal(list1, list2))
    {
        printf("As listas são iguais.\n");
    }
    else
    {
        printf("As listas são diferentes.\n");
    }

    return 0;
}
