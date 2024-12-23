/*
Descrição: A função list_find foi implementada para procurar a primeira ocorrência de um
elemento na lista. O algoritmo percorre o vetor de dados e compara cada elemento com o
valor procurado. Se encontrar uma correspondência, retorna a posição do elemento. Caso contrário,
retorna -1, indicando que o elemento não está presente na lista.
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectorlist.h"

// Função para encontrar a posição da primeira ocorrência do elemento
int list_find(VectorList *list, int elem)
{
    // Itera sobre todos os elementos da lista
    for (int i = 0; i < list->size; i++)
    {
        // Se encontrar o elemento, retorna a posição
        if (list->data[i] == elem)
        {
            return i;
        }
    }
    // Se não encontrar, retorna -1
    return -1;
}

int main()
{
    VectorList *list = new VectorList();
    list->push_back(1);
    list->push_back(4);
    list->push_back(3);
    list->push_back(44);
    list->push_back(23);

    list->print(); // Imprime a lista

    int elem = 44;
    int pos = list_find(list, elem); // Procura o elemento 3 na lista
    if (pos != -1)
    {
        printf("Elemento %d encontrado na posicao %d,\nNo %d lugar da lista\n",
               elem, pos, (pos + 1));
    }
    else
    {
        printf("Elemento %d não encontrado.\n", elem);
    }

    elem = 99;
    pos = list_find(list, elem); // Procura o elemento 10 (não presente)
    if (pos != -1)
    {
        printf("Elemento %d encontrado na posicao %d,\nNo %d lugar da lista\n",
               elem, pos, (pos + 1));
    }
    else
    {
        printf("Elemento %d não encontrado.\n", elem);
    }

    return 0;
}
