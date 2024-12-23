/*
Descrição: A função list_is_full foi implementada para verificar se a lista atingiu sua capacidade máxima.
Ela compara o valor de size (tamanho atual da lista) com capacity (capacidade máxima).
Se os dois valores forem iguais, a lista está cheia, e a função retorna 1 (verdadeiro).
Se não, retorna 0 (falso).
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectorlist.h"

// Implementação da função para verificar se a lista está cheia
int list_is_full(VectorList *list)
{
    if (list->size == list->capacity)
    {             // Se o tamanho da lista for igual à capacidade, está cheia
        return 1; // Retorna 1 (verdadeiro)
    }
    else
    {
        return 0; // Caso contrário, retorna 0 (falso)
    }
}

int main()
{
    VectorList *list = new VectorList();
    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    list->print();

    // Testa se a lista está cheia
    if (list_is_full(list))
    {
        printf("A lista esta cheia.\n");
    }
    else
    {
        printf("A lista nao esta cheia.\n");
    }

    // Adicionando mais elementos para testar o limite
    list->push_back(4);
    list->push_back(5);
    list->push_back(6); // Este deve falhar, pois a capacidade é 5
    list->print();

    // Testa novamente se a lista está cheia
    if (list_is_full(list))
    {
        printf("Agora a lista esta cheia.\n");
    }
    else
    {
        printf("A lista ainda nao esta cheia.\n");
    }

    return 0;
}
